#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

long long cross_product(Point o, Point a, Point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    if (n <= 2) {
        cout << n << "\n";
        for (auto i : p) cout << i.x << " " << i.y << "\n";
        return;
    }

    sort(p.begin(), p.end());
    
    vector<Point> hull;

    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), p[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_size && cross_product(hull[hull.size() - 2], hull.back(), p[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    hull.pop_back();

    cout << hull.size() << "\n";
    for (auto i : hull) {
        cout << i.x << " " << i.y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
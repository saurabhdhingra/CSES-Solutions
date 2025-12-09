#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;

    vector<Point> vertices(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> vertices[i].x >> vertices[i].y)) return;
    }

    ll total_signed_area_times_two = 0;

    for (int i = 0; i < N; ++i) {
        ll xi = vertices[i].x;
        ll yi = vertices[i].y;
        
        ll x_next = vertices[(i + 1) % N].x;
        ll y_next = vertices[(i + 1) % N].y;

        total_signed_area_times_two += (xi * y_next - x_next * yi);
    }

    ll result = abs(total_signed_area_times_two);

    cout << result << "\n";
}

int main() {
    solve();
    return 0;
}
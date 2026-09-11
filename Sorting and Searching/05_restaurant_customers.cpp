#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> events;
    events.reserve(2 * n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, +1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());

    int current = 0;
    int best = 0;
    for(auto& e : events) {
        current += e.second;
        best = max(best, current);
    }

    cout << best << "\n";

    return 0;
}

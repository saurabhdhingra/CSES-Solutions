#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<unsigned int> a(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        unsigned int x = 0;
        for(char c : s) {
            x = (x << 1) | (c - '0');
        }
        a[i] = x;
    }

    int best = k;
    for(int i = 0; i < n && best > 0; i++) {
        for(int j = i + 1; j < n; j++) {
            best = min(best, __builtin_popcount(a[i] ^ a[j]));
        }
    }

    cout << best << "\n";

    return 0;
}

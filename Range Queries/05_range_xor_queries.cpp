#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] ^ x;   // prefix XOR
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (pre[b] ^ pre[a - 1]) << '\n';
    }
    return 0;
}
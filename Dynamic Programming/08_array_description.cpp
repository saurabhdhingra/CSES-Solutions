#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // indices 0 and m+1 stay zero so v-1 / v+1 need no boundary checks
    vector<long long> dp(m + 2, 0);
    if(x[0] == 0) {
        for(int v = 1; v <= m; v++) {
            dp[v] = 1;
        }
    } else {
        dp[x[0]] = 1;
    }

    for(int i = 1; i < n; i++) {
        vector<long long> next(m + 2, 0);
        if(x[i] == 0) {
            for(int v = 1; v <= m; v++) {
                next[v] = (dp[v - 1] + dp[v] + dp[v + 1]) % MOD;
            }
        } else {
            int v = x[i];
            next[v] = (dp[v - 1] + dp[v] + dp[v + 1]) % MOD;
        }
        dp = std::move(next);
    }

    long long total = 0;
    for(int v = 1; v <= m; v++) {
        total = (total + dp[v]) % MOD;
    }

    cout << total << "\n";

    return 0;
}

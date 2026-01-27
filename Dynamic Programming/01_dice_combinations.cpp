#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int MOD = 1e9 + 7;
    // dp[i] stores the number of ways to reach sum i
    vector<int> dp(n + 1, 0);

    // Base case: one way to reach sum 0
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        // Look back at the last 6 possible dice rolls
        for (int die = 1; die <= 6; die++) {
            if (i - die >= 0) {
                dp[i] = (dp[i] + dp[i - die]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}
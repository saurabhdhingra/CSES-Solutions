#include <iostream>
#include <vector>
#include <algorithm>

// Define the modulus
const int MOD = 1e9 + 7;

void solve() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, X;
    
    // Read the number of coins (N) and the target sum (X)
    if (!(std::cin >> N >> X)) return;

    // Read the coin values
    std::vector<int> coins(N);
    for (int i = 0; i < N; ++i) {
        if (!(std::cin >> coins[i])) return;
    }

    // Initialize DP array. dp[i] stores the number of combinations to form sum i.
    // X can be up to 10^6, so an array of size X+1 is appropriate.
    std::vector<int> dp(X + 1, 0);

    // Base Case: One way to form sum 0 (using no coins)
    dp[0] = 1;

    // Outer loop: Iterate through each coin value
    // This fixed order prevents double counting combinations like {1, 2} and {2, 1}.
    for (int coin_value : coins) {
        for (int i = coin_value; i <= X; ++i) {
            dp[i] = (dp[i] + dp[i - coin_value]) % MOD;
        }
    }

    // The result is the number of combinations to form the target sum X
    std::cout << dp[X] << "\n";
}

int main() {
    solve();
    return 0;
}
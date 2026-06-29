#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if(!(cin >> n >> x)) return 0;

    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);

    dp[0] = 1;

    const int MOD = 1e9 + 7;

    for(int i = 1; i <= x; i++){
        for(int c : coins){
            if(i - c >= 0) {
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }

    cout << dp[x] << "\n";

    return 0;
}
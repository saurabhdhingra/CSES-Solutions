#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    if(!(cin >> n)) return 0;

    int INF = 1e9;

    vector<int> dp(n + 1, INF);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int tmp = i;

        while (tmp > 0){
            int dig = tmp % 10;
            tmp /= 10;
            
            if(dig > 0) {
                dp[i] = min(dp[i], dp[i - dig] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
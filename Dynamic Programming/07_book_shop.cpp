#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<int> dp(x + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = x; j >= prices[i]; j--){
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }

    cout << dp[x];

    return 0;
}
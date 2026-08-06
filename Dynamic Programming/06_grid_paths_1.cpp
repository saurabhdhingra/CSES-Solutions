#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if(!(cin >> N)) return 0;

    vector<string> grid(N, "");

    for(int i = 0; i < N; i++){
        cin >> grid[i];
    }

    // dp[j][r] = paths from (i, j) to (N-1, N-1); r = i & 1 is the current
    // row being filled, (i+1) & 1 holds the already-computed row below.
    vector<vector<int>> dp(N, vector<int>(2, 0));

    for(int i = N - 1; i >= 0; i--){
        int cur = i & 1;
        int nxt = (i + 1) & 1;
        for(int j = N - 1; j >= 0; j--){
            if(grid[i][j] == '*'){
                dp[j][cur] = 0;                        // trap: reset, don't reuse old value
            }else if(i == N - 1 && j == N - 1){
                dp[j][cur] = 1;                        // destination
            }else{
                long long down  = (i + 1 < N) ? dp[j][nxt]     : 0;  // (i+1, j)
                long long right = (j + 1 < N) ? dp[j + 1][cur] : 0;  // (i, j+1)
                dp[j][cur] = (down + right) % MOD;
            }
        }
    }

    cout << dp[0][0] << "\n";

    return 0;
}
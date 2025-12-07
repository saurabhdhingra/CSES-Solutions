#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, long long> DPState;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long X;

    if (!(cin >> N >> X)) return;

    vector<long long> W(N); 
    for (int i = 0; i < N; ++i) {
        if (!(cin >> W[i])) return;
    }

    int num_states = 1 << N;
    
    DPState INF = {N + 1, 0}; 
    vector<DPState> dp(num_states, INF);

    dp[0] = {1, 0}; 

    for (int mask = 1; mask < num_states; ++mask) {
        
        for (int i = 0; i < N; ++i) {
            
            if (mask & (1 << i)) {
                
                int prev_mask = mask ^ (1 << i); 
                
                int R_prev = dp[prev_mask].first;
                long long L_prev = dp[prev_mask].second;
              
                if (L_prev + W[i] <= X) {
                    DPState new_state = {R_prev, L_prev + W[i]};
                    dp[mask] = min(dp[mask], new_state);
                } 
                
                else {
                    DPState new_state = {R_prev + 1, W[i]};
                    dp[mask] = min(dp[mask], new_state);
                }
            }
        }
    }

    cout << dp[num_states - 1].first << "\n";
}

int main() {
    solve();
    return 0;
}
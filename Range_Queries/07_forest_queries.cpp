#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return;

    vector<vector<int>> prefix_sum(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        string row;
        if (!(cin >> row)) return;
        
        for (int j = 1; j <= N; ++j) {
            int is_tree = (row[j-1] == '*'); 
            
            prefix_sum[i][j] = is_tree + 
                               prefix_sum[i-1][j] + 
                               prefix_sum[i][j-1] - 
                               prefix_sum[i-1][j-1];
        }
    }

    for (int k = 0; k < Q; ++k) {
        int y1, x1, y2, x2;
        if (!(cin >> y1 >> x1 >> y2 >> x2)) return;

        int tree_count = prefix_sum[y2][x2] 
                       - prefix_sum[y1 - 1][x2] 
                       - prefix_sum[y2][x1 - 1] 
                       + prefix_sum[y1 - 1][x1 - 1];
                       
        cout << tree_count << "\n";
    }
}

int main() {
    solve();
    return 0;
}
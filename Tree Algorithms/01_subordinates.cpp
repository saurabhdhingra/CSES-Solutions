#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int subtree_size[MAXN];

void solve_dfs(int u) {
    subtree_size[u] = 0;
    for (int v : adj[u]) {
        solve_dfs(v);
        subtree_size[u] += (subtree_size[v] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    solve_dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << subtree_size[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}
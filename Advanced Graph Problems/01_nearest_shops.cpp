#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> shops(k);
    vector<bool> is_shop(n + 1, false);

    for(int i = 0; i < k; i++){
        cin >> shops[i];
        is_shop[shops[i]] = true;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, INF);
    vector<int> origin(n + 1, 0);
    vector<int> ans(n + 1, INF);
    queue<int> q;

    for (int shop : shops){
        dist[shop] = 0;
        origin[shop] = shop;
        q.push(shop);
    }

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v : adj[u]){
            if (dist[v] == INF){
                dist[v] = dist[u] + 1;
                origin[v] = origin[u];
                q.push(v);
            }else if (origin[v] != origin[u]) {
                int d = dist[u] + dist[v] + 1;
                ans[origin[v]] = min(ans[origin[v]], d);
                ans[origin[u]] = min(ans[origin[u]], d);
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        if (is_shop[i]){
            cout << (ans[i] == INF ? -1 : ans[i]) << (i == n ? "" : " ");
        } else {
            cout << (dist[i] == INF ? -1 : dist[i]) << (i == n ? "" : " ");
        }
    }

    cout << "\n";

    return 0;
}
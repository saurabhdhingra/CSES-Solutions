#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, 0);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == n) break;

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(!visited[n]) {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    vector<int> path;
    for(int u = n; u != 1; u = parent[u]) {
        path.push_back(u);
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int i = 0; i < (int)path.size(); i++) {
        cout << path[i] << " \n"[i == (int)path.size() - 1];
    }

    return 0;
}

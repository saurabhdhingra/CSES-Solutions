#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;

vector<int> bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.assign(n + 1, {});
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist = bfs(1, n);

    int u = 1;
    for(int i = 1; i <= n; i++) {
        if(dist[i] > dist[u]) {
            u = i;
        }
    }

    dist = bfs(u, n);

    int diameter = 0;
    for(int i = 1; i <= n; i++) {
        diameter = max(diameter, dist[i]);
    }

    cout << diameter << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs(int start, int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if (dist[v] == -1) {
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

    if(n == 1){
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> d1 = bfs(1, n, adj);
    int A = 1;
    for(int i = 1; i <= n; i++){
        if (d1[i] > d1[A]) A = i;
    }

    vector<int> distA = bfs(A, n, adj);
    int B = A;
    for(int i = 1; i <= n; i++){
        if(distA[i] > distA[B]) B = i;
    }

    vector<int> distB = bfs(B, n, adj);

    for(int i = 1; i <= n; i++){
        cout << max(distA[i], distB[i]) << (i == n ? "" : " ");
    }

    cout << "\n";

    return 0;
}
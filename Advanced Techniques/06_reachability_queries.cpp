#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const int MAXN = 50005;

int n, m, q;

vector<int> adj[MAXN], adj_rev[MAXN];
vector<int> dag[MAXN];
vector<int> order;
bool visited[MAXN];
int component_id[MAXN];
int comp_cnt = 0;

// Bitset array to store reachability for each component
// Size must be a constant known at compile time
bitset<MAXN> reach[MAXN];

void dfs1(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if (!visited[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int rep){
    visited[u] = true;
    component_id[u] = rep;
    for(int v : adj_rev[u]) {
        if (!visited[v]) dfs2(v, rep);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> q)) return 0;

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    // Find SCCs using Kosaraju's ALgorithm
    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs1(i);
    }

    fill(visited, visited + n + 1, false);
    reverse(order.begin(), order.end());

    for(int u : order){
        if(!visited[u]) {
            dfs2(u, comp_cnt);
            comp_cnt++;
        }
    }

    for (int u = 1; u <= n; u++){
        int u_comp = component_id[u];
        for(int v : adj[u]){
            int v_comp = component_id[v];
            if(u_comp != v_comp) {
                dag[u_comp].push_back(v_comp);
            }
        }
    }

    for(int i = 0; i < comp_cnt; i++){
        sort(dag[i].begin(), dag[i].end());
        dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }


    for(int i = comp_cnt - 1; i >= 0; i--){
        reach[i].set(i);
        for (int next_comp : dag[i]) {
            reach[i] |= reach[next_comp];
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        int comp_a = component_id[a];
        int comp_b = component_id[b];

        if (reach[comp_a].test(comp_b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
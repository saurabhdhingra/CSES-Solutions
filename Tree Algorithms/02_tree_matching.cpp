#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0), order;
    vector<bool> visited(n + 1, false);
    order.reserve(n);
    vector<int> st;
    st.push_back(1);
    visited[1] = true;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                st.push_back(v);
            }
        }
    }

    vector<bool> matched(n + 1, false);
    int ans = 0;
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        int p = parent[u];
        if (p != 0 && !matched[u] && !matched[p]) {
            matched[u] = true;
            matched[p] = true;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}

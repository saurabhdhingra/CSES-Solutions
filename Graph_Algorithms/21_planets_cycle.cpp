#include<iostream>
#include<vector>

using namespace std;

int N;

int cycleJumps(int u, int v, vector<int>& teleporters){
    vector<bool> vis(teleporters.size(), false);

    int cur = u;
    int nxt = v;

    int jmp = 0;

    while(!vis[cur - 1]){
        vis[cur - 1] = true;
        cur = nxt;
        nxt = teleporters[nxt - 1];
        jmp++;
    }
    
    return jmp;
}

void solve() {
    if(!(cin >> N)) return;

    vector<int> tel(N, -1);

    for(int I = 0; I < N; I++){
        if(!(cin >> tel[I])) return;
    }

    for(int i = 0; i < N; i++){
       cout << cycleJumps(i + 1, tel[i], tel) << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
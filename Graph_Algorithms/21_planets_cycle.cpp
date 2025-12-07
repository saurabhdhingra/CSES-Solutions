#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

int next_planet[MAXN];

int ans[MAXN];

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;

    for(int i = 1; i <= N; ++i){
        cin >> next_planet[i];
    }

    for(int i = 1; i <= N; ++i){
        if(ans[i] == 0){

            map<int, int> visited_path;
            vector<int> path;

            int curr = i;
            int dist = 0;

            while(ans[curr] == 0 && visited_path.find(curr) == visited_path.end()){
                visited_path[curr] = dist;
                path.push_back(curr);
                curr = next_planet[curr];
                dist++;
            }

            if(ans[curr] != 0){
                int path_len_to_curr = dist;

                for(int u : path){
                    ans[u] = ans[curr] + (path_len_to_curr - visited_path[u]);
                }
            }
            else{
                int cycle_start_dist = visited_path[curr];
                int cycle_length = path.size() - cycle_start_dist;

                for(size_t j = cycle_start_dist; j < path.size(); ++j){
                    ans[path[j]] = cycle_length;
                }

                for(int j = 0; j < cycle_start_dist; ++j){
                    ans[path[j]] = cycle_length + (cycle_start_dist - j);
                }
            }
        }
    }

    for(int i = 1; i <= N; ++i){
        cout << ans[i] << (i == N ? "" : " ");
    }
    cout << "\n";
}

int main(){
    solve();
    return 0;
}
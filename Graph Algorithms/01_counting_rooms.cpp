#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> grid;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (grid[x][y] != '.') return false;
    return true;
}

void dfs(int x, int y){
    grid[x][y] = '#';

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx, ny)){
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(!(cin >> n >> m)) return 0;

    grid.resize(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    int room_count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                room_count++;
                dfs(i, j);
            }
        }
    }

    cout << room_count << "\n";

    return 0;
}
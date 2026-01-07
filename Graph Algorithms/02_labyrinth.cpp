#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Defines the movements (Up, Down, Left, Right)
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
string move_dir = "UDLR";

void solve() {
    int R, C;
    if (!(cin >> R >> C)) return;

    vector<string> grid(R);
    int start_r = -1, start_c = -1;
    int end_r = -1, end_c = -1;

    // Read grid and find start/end points
    for (int i = 0; i < R; ++i) {
        if (!(cin >> grid[i])) return;
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'A') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'B') {
                end_r = i;
                end_c = j;
            }
        }
    }

    // Stores the direction taken to reach (r, c)
    // E.g., if we came from left, parent[r][c] = 'R'
    vector<vector<char>> parent(R, vector<char>(C, ' '));
    
    // Queue for BFS: stores {row, column}
    queue<pair<int, int>> q;
    q.push({start_r, start_c});

    // Flag to indicate if 'B' has been found
    bool found = false;

    // --- 1. BFS for Pathfinding ---
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        if (r == end_r && c == end_c) {
            found = true;
            break;
        }

        // Try all four directions
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            char dir = move_dir[i];

            // Check if (nr, nc) is valid
            if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                grid[nr][nc] != '#' && parent[nr][nc] == ' ') {
                
                // Valid move: Mark the path and enqueue
                parent[nr][nc] = dir;
                q.push({nr, nc});

                if (nr == end_r && nc == end_c) {
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
    }

    // --- 2. Path Reconstruction ---
    if (found) {
        string path = "";
        int r = end_r;
        int c = end_c;

        while (r != start_r || c != start_c) {
            char dir = parent[r][c];
            path += dir;

            // Move backward one step (opposite of the stored direction)
            if (dir == 'U') r++;
            else if (dir == 'D') r--;
            else if (dir == 'L') c++;
            else if (dir == 'R') c--;
        }

        reverse(path.begin(), path.end());

        cout << "YES" << "\n";
        cout << path.length() << "\n";
        cout << path << "\n";

    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Standard fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
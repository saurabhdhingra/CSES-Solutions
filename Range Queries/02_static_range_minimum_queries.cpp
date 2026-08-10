#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int LOGN = 18;

int st[LOGN][MAXN];
int bin_log[MAXN];

void precomputeLogs(int n){
    bin_log[1] = 0;
    for(int i = 2; i <= n; i++){
        bin_log[i] = bin_log[i / 2] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> st[0][i];
    }

    for(int j = 1; j < LOGN; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }

    precomputeLogs(n);

    while(q--){
        int L, R;
        cin >> L >> R;
        L--; R--;

        int j = bin_log[R - L + 1];
        int ans = min(st[j][L], st[j][R - (1 << j) + 1]);
        cout << ans << "\n";
    }

    return 0;
}

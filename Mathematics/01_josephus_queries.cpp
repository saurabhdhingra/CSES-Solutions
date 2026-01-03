#include <iostream>

using namespace std;

int solve(int n, int k){
    if (n == 1) return 1;
    
    if(k <= (n + 1) / 2) {
        if (2 * k > n) return 1;
        return 2 * k;
    }

    int res = solve(n / 2, k - (n + 1) / 2);

    if((n & 1) == 0){
        return 2 * res - 1;
    }else {
        return 2 * res + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--){
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }

    return 0;
}


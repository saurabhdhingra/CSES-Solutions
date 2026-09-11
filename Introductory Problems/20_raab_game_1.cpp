#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        // equal card sums force every non-tie round to be answered back,
        // so one-sided scores (a=0 xor b=0) are impossible
        bool possible = (a == 0 && b == 0) || (a >= 1 && b >= 1 && a + b <= n);
        if(!possible) {
            cout << "NO" << "\n";
            continue;
        }

        cout << "YES" << "\n";

        int k = a + b;
        vector<int> p1, p2;

        // ties: both play the same low card
        for(int c = 1; c <= n - k; c++) {
            p1.push_back(c);
            p2.push_back(c);
        }

        // battle: top k cards; p1 plays them rotated by b, giving
        // exactly a wins (no wrap) and b losses (wrap), no ties
        for(int i = 0; i < k; i++) {
            p1.push_back(n - k + 1 + (i + b) % k);
            p2.push_back(n - k + 1 + i);
        }

        for(int i = 0; i < n; i++) {
            cout << p1[i] << " \n"[i == n - 1];
        }
        for(int i = 0; i < n; i++) {
            cout << p2[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}

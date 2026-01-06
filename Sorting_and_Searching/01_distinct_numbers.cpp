#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int distinct_count = 1; 
    for (int i = 1; i < n; i++) {
        if (x[i] != x[i - 1]) {
            distinct_count++;
        }
    }

    cout << distinct_count << endl;

    return 0;
}
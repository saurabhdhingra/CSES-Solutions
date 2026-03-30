#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n), apartment(m);

    for (int i = 0; i < n; i++) cin >> desired[i];
    for (int i = 0; i < m; i++) cin >> apartment[i];

    sort(desired.begin(), desired.end());
    sort(apartment.begin(), apartment.end());

    int i = 0, j = 0, count = 0;

    while (i < n && j < m) {
        if (apartment[j] < desired[i] - k) {
            // Apartment too small for this applicant — skip apartment
            j++;
        } else if (apartment[j] > desired[i] + k) {
            // Apartment too large — no suitable apartment for this applicant
            i++;
        } else {
            // Valid match!
            count++;
            i++;
            j++;
        }
    }

    cout << count << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n), apartment(m);
    for (int i = 0; i < n; i++) {
        cin >> desired[i];
    }

    for (int j = 0; j < m; j++) {
        cin >> apartment[j];
    }

    sort(desired.begin(), desired.end());
    sort(apartment.begin(), apartment.end());

    int i = 0, j = 0, count = 0;

    while (i < n && j < m){
        if (apartment[j] >= desired[i] - k && apartment[j] <= desired[i] + k){
            count++;
            i++;
            j++;
        }
        else if (apartment[j] < desired[i] - k){
            j++;
        }
        else {
            i++;
        }
    }

    cout << count << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }

    // every border of length b gives a period n - b; the chain
    // pi[n-1], pi[pi[n-1]-1], ... visits borders in decreasing order,
    // so periods come out increasing; n itself (empty border) is last
    vector<int> periods;
    for(int b = pi[n - 1]; b > 0; b = pi[b - 1]) {
        periods.push_back(n - b);
    }
    periods.push_back(n);

    for(int i = 0; i < (int)periods.size(); i++) {
        cout << periods[i] << " \n"[i == (int)periods.size() - 1];
    }

    return 0;
}

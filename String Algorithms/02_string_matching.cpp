#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    if (!(cin >> text >> pattern)) return 0;

    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int count = 0;
    int i = 0; 
    int j = 0; 
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1]; 
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
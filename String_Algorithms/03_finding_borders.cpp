#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to compute the KMP prefix function (pi array)
vector<int> compute_prefix_function(const string& s) {
    int n = s.length();
    vector<int> pi(n);
    pi[0] = 0; // Base case: the longest proper prefix of length 1 is length 0

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        // j is the length of the previous longest border
        
        // While the characters don't match, fall back to the border of the border
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        
        // If characters match, extend the border
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    if (!(cin >> S)) return;

    int N = S.length();
    if (N == 0) return;

    // 1. Compute the prefix function in O(N)
    vector<int> pi = compute_prefix_function(S);

    // 2. Find all border lengths
    vector<int> border_lengths;
    
    // Start with the length of the longest proper border of the entire string S
    int L = pi[N - 1];

    // Repeatedly apply the prefix function to find all borders (borders of borders)
    // The length L is a border length if L > 0
    while (L > 0) {
        border_lengths.push_back(L);
        // The next border length is pi[L - 1], the length of the longest border of S[0...L-1]
        L = pi[L - 1]; 
    }
    
    // 3. Output the results
    // The problem asks for the lengths in increasing order. 
    // Since we collected them from largest to smallest, we must reverse the vector.
    reverse(border_lengths.begin(), border_lengths.end());

    // Print all lengths separated by spaces
    for (int i = 0; i < border_lengths.size(); ++i) {
        cout << border_lengths[i] << (i == border_lengths.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;
    int n = s.length();

    int k;
    cin >> k;

    // Build a trie of the dictionary words. trie[node][c] = child index or -1.
    // isEnd[node] marks the end of a dictionary word.
    vector<array<int, 26>> trie(1);
    trie[0].fill(-1);
    vector<bool> isEnd(1, false);

    for (int i = 0; i < k; i++) {
        string w;
        cin >> w;
        int cur = 0;
        for (char ch : w) {
            int c = ch - 'a';
            if (trie[cur][c] == -1) {
                trie[cur][c] = (int)trie.size();
                trie.push_back(array<int, 26>());
                trie.back().fill(-1);
                isEnd.push_back(false);
            }
            cur = trie[cur][c];
        }
        isEnd[cur] = true;
    }

    // dp[i] = number of ways to build the first i characters of s.
    // From each reachable position i, walk the trie over s[i..] and whenever a
    // word ends at position j, add dp[i] to dp[j + 1].
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;
        int cur = 0;
        for (int j = i; j < n; j++) {
            int c = s[j] - 'a';
            if (trie[cur][c] == -1) break;
            cur = trie[cur][c];
            if (isEnd[cur]) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}

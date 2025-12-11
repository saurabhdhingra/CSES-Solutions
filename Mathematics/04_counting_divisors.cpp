#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Maximum value for x in the problem constraints
const int MAX_VAL = 1000000;

// Array to store the pre-calculated number of divisors for each number up to MAX_VAL
// We initialize it to a size of MAX_VAL + 1 for 1-based indexing.
vector<int> div_count(MAX_VAL + 1, 0);

void precompute_divisors() {
    // Sieve Method: Iterate through all numbers i, and mark all their multiples j.
    // Each time j is marked, it means i is a divisor of j.
    for (int i = 1; i <= MAX_VAL; ++i) {
        // Iterate through all multiples j of i, starting from i itself.
        // We use 'long long' for j * i just to prevent potential overflow 
        // during the calculation, although j * i should stay within int range 
        // if j is max N and i is max N, but the current loop is safer by only using i as multiplier.
        for (int j = i; j <= MAX_VAL; j += i) {
            div_count[j]++;
        }
    }
}

void solve() {
    // The number of queries N is read, but the main work is the precomputation.
    int N;
    if (!(cin >> N)) return;

    // --- Step 1: Precomputation (O(MAX_VAL log MAX_VAL)) ---
    precompute_divisors();

    // --- Step 2: Answering Queries (O(1) per query) ---
    for (int i = 0; i < N; ++i) {
        int x;
        if (!(cin >> x)) return;

        // Output the pre-calculated result
        cout << div_count[x] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
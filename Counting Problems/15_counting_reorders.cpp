#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 1000000007;
const int MAXN = 5005;

long long fact[MAXN];
long long invFact[MAXN];

// Modular Exponentiation
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// Function to multiply two polynomials modulo MOD
vector<long long> multiply(const vector<long long>& A, const vector<long long>& B) {
    vector<long long> res(A.size() + B.size() - 1, 0);
    for (int i = 0; i < A.size(); i++) {
        // Optimization: Skip zero coefficients
        if (A[i] == 0) continue; 
        
        for (int j = 0; j < B.size(); j++) {
            res[i + j] = (res[i + j] + A[i] * B[j]) % MOD;
        }
    }
    return res;
}

int main() {
    // Standard Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    string s;
    if (!(cin >> s)) return 0;

    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;

    // Current Result Polynomial. Initialize with 1 (polynomial: [1])
    vector<long long> P = {1};

    // 1. Construct and Multiply Polynomials
    for (int i = 0; i < 26; i++) {
        int n = freq[i];
        if (n == 0) continue;

        // Construct P_char(x)
        // Terms range from x^1 to x^n (so size is n+1)
        vector<long long> poly(n + 1, 0);
        
        for (int j = 1; j <= n; j++) {
            // Term calculation: (-1)^(n-j) * C(n-1, j-1) * (1/j!)
            long long term = nCr(n - 1, j - 1);
            term = (term * invFact[j]) % MOD;
            
            if ((n - j) % 2 == 1) {
                term = (MOD - term) % MOD;
            }
            
            poly[j] = term;
        }

        // 2. Multiply accumulated P with current char's poly
        P = multiply(P, poly);
    }

    // 3. Final Summation: sum(coeff[k] * k!)
    long long ans = 0;
    for (int k = 0; k < P.size(); k++) {
        if (P[k] == 0) continue;
        long long term = (P[k] * fact[k]) % MOD;
        ans = (ans + term) % MOD;
    }

    cout << ans << endl;

    return 0;
}
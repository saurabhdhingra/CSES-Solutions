#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

long long modpow(long long base, long long exp, long long mod) {
    base %= mod;
    long long result = 1;
    while(exp > 0) {
        if(exp & 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if(a % MOD == 0) {
            // Fermat needs gcd(a, MOD) = 1; 0^(b^c) is 0 unless b^c = 0 (0^0 = 1)
            cout << ((b == 0 && c >= 1) ? 1 : 0) << "\n";
        } else {
            long long e = modpow(b, c, MOD - 1);
            cout << modpow(a, e, MOD) << "\n";
        }
    }

    return 0;
}

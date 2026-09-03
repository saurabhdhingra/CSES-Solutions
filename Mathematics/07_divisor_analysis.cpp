#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll power(ll a, ll b, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Modular inverse mod the prime MOD via Fermat's little theorem.
ll inv(ll a) {
    return power(a, MOD - 2, MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<ll> x(n), k(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> k[i];

    // Number of divisors: product of (k_i + 1).
    ll count = 1;
    for (int i = 0; i < n; i++) {
        count = count * ((k[i] + 1) % MOD) % MOD;
    }

    // Sum of divisors: product of geometric series (x^(k+1) - 1) / (x - 1).
    // x - 1 in [1, 10^6 - 1] is always invertible mod MOD.
    ll sum = 1;
    for (int i = 0; i < n; i++) {
        ll numerator = (power(x[i], k[i] + 1, MOD) - 1 + MOD) % MOD;
        ll term = numerator * inv((x[i] - 1) % MOD) % MOD;
        sum = sum * term % MOD;
    }

    // Product of divisors: prod x_i^(E_i), with
    //   E_i = (k_i(k_i+1)/2) * prod_{j != i} (k_j + 1).
    // gcd(N, MOD) = 1, so exponents are taken mod (MOD - 1) by Fermat.
    const ll MOD2 = MOD - 1;
    vector<ll> pref(n + 1, 1), suf(n + 1, 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] * ((k[i] + 1) % MOD2) % MOD2;
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] * ((k[i] + 1) % MOD2) % MOD2;

    ll product = 1;
    for (int i = 0; i < n; i++) {
        // k_i(k_i+1) fits in ll (<= ~1e18) and is even, so compute the exact
        // integer k_i(k_i+1)/2 first, THEN reduce (dividing after a mod by an
        // even modulus would be wrong).
        ll half = k[i] * (k[i] + 1) / 2 % MOD2;
        ll cross = pref[i] * suf[i + 1] % MOD2;   // product of (k_j + 1), j != i
        ll e = half * cross % MOD2;
        product = product * power(x[i], e, MOD) % MOD;
    }

    cout << count << " " << sum << " " << product << "\n";

    return 0;
}

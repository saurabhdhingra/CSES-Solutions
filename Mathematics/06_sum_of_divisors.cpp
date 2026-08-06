#include <iostream>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INV2 = 500000004; 

ll sum_n(ll n) {
    n %= MOD;
    return n * (n + 1) % MOD * INV2 % MOD;
}

int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    ll l = 1;

   
    while (l <= n) {
        ll k = n / l;     
        ll r = n / k;      
        
        if (r > n) r = n;

        ll range_sum = (sum_n(r) - sum_n(l - 1) + MOD) % MOD;

        ans = (ans + (k % MOD) * range_sum) % MOD;

        l = r + 1; 
    }

    cout << ans << "\n";

    return 0;
}
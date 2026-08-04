#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    base %= MOD;
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << power(a, b) << "\n";
    }

    return 0;
}

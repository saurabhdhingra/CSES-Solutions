#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXV = 1000001;

int cnt[MAXV];
int min_prime[MAXV];

void precompute_spf() {
    for (int i = 1; i < MAXV; i++) min_prime[i] = i;
    for (int i = 2; i * i < MAXV; i++) {
        if(min_prime[i] == i) {
            for (int j = i * i; j < MAXV; j += i) {
                if (min_prime[j] == j) {
                    min_prime[j] = i;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_spf();

    int n;
    if (!(cin >> n)) return 0;

    ll coprime_pairs = 0;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        vector<int> primes;
        int temp = x;
        while (temp > 1) {
            int p = min_prime[temp];
            primes.push_back(p);
            while (temp % p == 0) {
                temp /= p;
            }
        }

        int k = primes.size();
        int not_coprime_count = 0;

        for (int mask = 1; mask < (1 << k); mask++){
            int prod = 1;
            int bits = 0;

            for (int j = 0; j < k; j++){
                if ((mask >> j) & 1) {
                    prod *= primes[j];
                    bits++;
                }
            }

            if(bits % 2 == 1){
                not_coprime_count += cnt[prod];
            } else {
                not_coprime_count -= cnt[prod];
            }
        }

        int current_coprime = i - not_coprime_count;
        coprime_pairs += current_coprime;

        for (int mask = 1; mask < (1 << k); mask++) {
            int prod = 1;
            for (int j = 0; j < k; j++){
                if ((mask >> j) & 1) {
                    prod *= primes[j];
                }
            }

            cnt[prod]++;
        }
    }

    cout << coprime_pairs << "\n";

    return 0;
}
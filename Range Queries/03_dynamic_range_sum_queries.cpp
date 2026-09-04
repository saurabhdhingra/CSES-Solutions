#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<long long> tree;

void update(int k, long long delta) {
    for(; k <= n; k += k & -k) {
        tree[k] += delta;
    }
}

long long sum(int k) {
    long long s = 0;
    for(; k >= 1; k -= k & -k) {
        s += tree[k];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    tree.assign(n + 1, 0);
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            update(k, u - a[k]);
            a[k] = u;
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << "\n";
        }
    }

    return 0;
}

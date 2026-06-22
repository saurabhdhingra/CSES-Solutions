#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    while (left <= right){
        if(p[left] + p[right] <= x){
            left++;
            right--;
        }else {
            right--;
        }
        gondolas++;
    }

    cout << gondolas << "\n";

    return 0;
}
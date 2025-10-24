#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int N;

    if(!(cin >> N)) return;

    vector<int> arr(N);

    for(int i = 0; i < N; i++){
        int x;
        if(!(cin >> x)) return;
        arr[x] = i;
    }

    long long res = 1;

    for(int X = 2; X <= N; ++X){
        int curPos = arr[X];
        int prePos = arr[X - 1];
        
        if (curPos < prePos){
            res++;
        }
    }

    cout << res << "\n";
}


int main() {
    //Using fast io for better performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
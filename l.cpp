#include <bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int cnt[30];
    memset(cnt, 0, sizeof cnt);
    for(int i=0;i<n;i++){
        for(int j=0;j<30;j++){
            cnt[j] += (a[i]&(1<<j)) != 0;
        }
    }

    for(int i=0;i<n;i++){
        int cur = 0;
        for(int j=0;j<30;j++){
            if(!cnt[j]) continue;
            cnt[j]--;
            cur |= (1 << j);
        }
        cout << cur << ' ';
    }
    cout << '\n';

    return 0;
}

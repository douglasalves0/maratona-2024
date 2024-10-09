#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n;
    cin >> n;

    ll num = 1, den = 1;
    for(ll i=0;i<n;i++){
        ll nnum = den, nden = num + den;
        num = nnum;
        den = nden;
    }

    cout << num << '\n';

    return 0;
}

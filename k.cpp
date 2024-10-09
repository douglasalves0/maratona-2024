#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main(){

    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll a[n], sum = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum % 2){
        cout << "-1\n";
        return 0;
    }

    pii f[sum+1];
    for(ll i=1;i<=sum;i++) f[i] = {0,-1};
    f[0] = {1, -1};
    for(ll i=0;i<n;i++){
        for(ll j=sum;j;j--){
            auto &[can, idx] = f[j];
            if(can || j - a[i] < 0) continue;
            auto [o, _] = f[j - a[i]];
            if(!o) continue;
            can = 1;
            idx = i;
        }
    }

    if(f[sum/2].first == 0){
        cout << "-1\n";
        return 0;
    }

    multiset<ll> bob;
    for(ll i=0;i<n;i++) bob.insert(a[i]);

    multiset<ll> alice;
    ll cursum = sum/2;
    while(cursum){
        auto [_, idx] = f[cursum];
        alice.insert(a[idx]);
        bob.extract(a[idx]);
        cursum -= a[idx];
    }

    ll x = 0, y = 0; // alice, bob
    for(ll i=0;i<n;i++){
        if(x <= y){
            x += *alice.begin();
            cout << *alice.begin() << ' ';
            alice.extract(*alice.begin());
        }else{
            y += *bob.begin();
            cout << *bob.begin() << ' ';
            bob.extract(*bob.begin());
        }
    }
    cout << '\n';

    return 0;
}

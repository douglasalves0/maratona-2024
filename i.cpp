#include <bits/stdc++.h>
using namespace std;

#pragma once

typedef long long ll;

const ll MAXN = 1e5;
const ll MAXAI = 1e6;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll lpf[MAXAI+1];
void sieve(){
    for(ll i=2;i<=MAXAI;i++){
        if(lpf[i] != INF) continue;
        for(ll j=i;j<=MAXAI;j+=i) lpf[j] = i;
    }
}

vector<ll> fact(ll x){
    vector<ll> ans;
    while(lpf[x] != INF){
        ans.push_back(lpf[x]);
        ll y = lpf[x];
        while(lpf[x] == y) x /= lpf[x];
    }
    return ans;
}

signed main(){

    cin.tie(0)->sync_with_stdio(0);

    fill(lpf, lpf+(MAXAI+1), INF);
    sieve();

    ll p2[MAXN+1];
    p2[0] = 1;
    for(ll i=1;i<=MAXN;i++) p2[i] = p2[i-1] * 2 % MOD;

    ll n;
    cin >> n;

    ll a[n], cnt[MAXAI+1];
    memset(cnt, 0, sizeof cnt);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        auto v = fact(a[i]);
        function<void(ll,ll,ll)> cntdivisors = [&](ll i, ll num, ll c){
            if(i == v.size()){
                if(num != 1) cnt[num]++;
                return;
            }
            cntdivisors(i+1, num, c);
            cntdivisors(i+1, num * v[i], c+1);
        };
        cntdivisors(0,1,0);
    }

    ll q;
    cin >> q;

    while(q--){
        ll x;
        cin >> x;
        auto v = fact(x);
        ll ans = 0;
        function<void(ll,ll,ll)> brute = [&](ll i, ll num, ll c){
            if(i == v.size()){
                if(c%2) ans += cnt[num];
                else ans -= cnt[num];
                return;
            }
            brute(i+1, num, c);
            brute(i+1, num * v[i], c+1);
        };
        brute(0,1,0);
        cout << p2[n - ans] << '\n';
    }

    return 0;
}

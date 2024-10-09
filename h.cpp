#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main(){

    cin.tie(0)->sync_with_stdio(0);

    string s[2];
    cin >> s[0] >> s[1];

    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());

    vector<pii> incognito;
    for(int i=0;i<2;i++){
        for(int j=0;j<s[i].size();j++){
            if(s[i][j] != '*') continue;
            incognito.push_back({i,j});
        }
    }

    function<void(int)> brute = [&](int i){
        if(i == incognito.size()){
            ll mod = 0, cur = 1;
            for(int i=0;i<s[1].size();i++){
                mod += cur * (s[1][i] - '0');
                cur *= 2;
            }
            ll num = 0;
            cur = 1;
            for(int i=0;i<s[0].size();i++){
                num += cur * (s[0][i] - '0');
                num %= mod;
                cur *= 2;
                cur %= mod;
            }
            if(num == 0){
                reverse(s[0].begin(), s[0].end());
                cout << s[0] << '\n';
                exit(0);
            }
            return;
        }
        auto [x,y] = incognito[i];
        s[x][y] = '0';
        brute(i+1);
        s[x][y] = '1';
        brute(i+1);
        s[x][y] = '*';
    };
    
    brute(0);

    cout << "WTF?\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

struct dsu {
    vector<int> p, rnk;
    dsu(int n) : p(n), rnk(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        p[b] = a;
        rnk[a] += rnk[b];
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
};

signed main(){

    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector <int> actors[n+1];
    bool isactoronfilm[m+1][n+1];
    memset(isactoronfilm, 0, sizeof isactoronfilm);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        actors[i].resize(x);
        for(int j=0;j<x;j++){
            int y;
            cin >> y;
            actors[i][j] = y;
            isactoronfilm[y][i] = 1;
        }
    }

    dsu comps(n+1);
    vector <pii> graph[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            for(int k: actors[i]){
                if(!isactoronfilm[k][j]) continue;
                if(comps.find(i) == comps.find(j)) continue;
                comps.join(i, j);
                graph[i].push_back({j, k});
                graph[j].push_back({i, k});
            }
        }
    }

    int q;
    cin >> q;

    while(q--){

        int x, y;
        cin >> x >> y;

        vector <pii> par(n+1, {0,0});
        queue <int> qu;
        for(int i=1;i<=n;i++){
            if(!isactoronfilm[x][i]) continue;
            qu.push(i);
            par[i] = {i, x};
        }

        int last = 0;
        while(!qu.empty()){
            int v = qu.front();
            qu.pop();
            if(isactoronfilm[y][v]){
                last = v;
                break;
            }
            for(auto [u, mid]: graph[v]){
                auto [p, _] = par[u];
                if(p) continue;
                par[u] = {v, mid};
                qu.push(u);
            }
        }

        if(!last){
            cout << "-1\n";
            continue;
        }

        vector <int> ans;
        ans.push_back(y);
        while(1){
            auto [p, mid] = par[last];
            if(p == last) break;
            ans.push_back(last);
            ans.push_back(mid);
            last = p;
        }
        ans.push_back(last);
        ans.push_back(x);
        reverse(ans.begin(), ans.end());

        cout << ans.size() / 2 + 1 << '\n';
        for(int o: ans) cout << o << ' ';
        cout << '\n';

    }

}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    int a[50][50];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    auto rotate = [&](){
        int b[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                b[n-1-j][i] = a[i][j];
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j] = b[i][j];
    };

    auto check = [&](){
        bool okr = 1, okc = 1;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                okr &= a[i][j] > a[i][j-1];
            }
        }
        for(int j=0;j<n;j++){
            for(int i=1;i<n;i++){
                okc &= a[i][j] > a[i-1][j];
            }
        }
        return okr && okc;
    };

    for(int i=0;i<4;i++){
        if(check()){
            cout << i << '\n';
            return 0;
        }
        rotate();
    }

    cout << "WTF?\n";

    return 0;
}

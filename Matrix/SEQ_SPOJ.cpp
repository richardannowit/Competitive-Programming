/*

        M           *       A      =   res

| c1 c2 c3 ... ck |     | ak    |    | ak+1  |
| 1  0  0  ... 0  |     | ak-1  |    | ak    |
| 0  1  0  ... 0  |  *  | ak-2  |  = | ak-1  |
| ..............  |     | ....  |    | ....  |
| 0  0  0...1  0  |     | a1    |    | a2    |    <===

 */

#include<bits/stdc++.h>
#define MAXN 6
#define oo 1e9
#define ll long long

using namespace std;
const ll mod = 1e9;

struct Matrix{
    int v[15][15];
    int row, col;
};

Matrix multiply(Matrix A, Matrix B){
    Matrix r;
    r.row = A.row; r.col = B.col;
    for(int i=1; i<=r.row; i++){
        for(int j=1; j<=r.col; j++){
            r.v[i][j] = 0;
            for(int k=1; k<=A.col; k++){
                r.v[i][j] +=(1LL*A.v[i][k]%mod*B.v[k][j]%mod);
                r.v[i][j] %=mod;
            }
        }
    }
    return r;
}

Matrix power(Matrix A, ll p){
    if(p==1) return A;
    if(p%2==1) return multiply(A, power(A, p-1));
    Matrix r = power(A,p/2);
    r = multiply(r,r);
    return r;
}

int main(){
    //RF;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin>>tc;
    while(tc--){
        int k; cin>>k;
        int b[11], c[11];
        for(int i=1; i<=k; i++){
            cin>>b[i];
        }
        for(int i=1; i<=k; i++) {
            cin >> c[i];
        }
        ll n; cin>>n;

        if(n<=k){
            cout << b[n] << endl;
            continue;
        }
        n-=(ll)k;
        Matrix M; M.col = k; M.row = k;
        for(int i=1; i<=M.col; i++)
            for(int j=1; j<=M.row; j++) M.v[i][j] = 0;

        for(int i=1; i<=k; i++) M.v[1][i] = c[i];
        for(int i=2; i<=M.row; i++){
            M.v[i][i-1] = 1;
        }
        Matrix A; A.row = k; A.col = 1;
        for(int i=1; i<=A.row; i++){
            A.v[i][1] = b[k-i+1];
        }
        M = power(M, n);
        Matrix res; res.col = 1; res.row = k;
        res = multiply(M, A);
        cout << res.v[1][1] %mod << endl;

    }
    return 0;
}

#include<bits/stdc++.h>
#define MAXN 6
#define oo 1e9
#define ll long long

using namespace std;
const ll mod = 1e9+7;

struct Matrix{
    int v[MAXN][MAXN];
    int row, col;
};

Matrix multiply(Matrix A, Matrix B){
    Matrix r;
    r.row = A.row;
    r.col = B.col;
    for(int i=0; i<r.row; i++){
        for(int j=0; j<r.col; j++){
            r.v[i][j] = 0;
            for(int k=0; k<A.col; k++){
                r.v[i][j] += (1LL*A.v[i][k]%mod*B.v[k][j]%mod);
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
    int tc;
    cin>>tc;
    Matrix M; M.col = M.row = 5;
    for(int i=0;i<5; i++)
        for(int j=0; j<5; j++) M.v[i][j] = 0;
    M.v[0][0]=1; M.v[0][1]=2;M.v[0][2]=0;M.v[0][3]=5;M.v[0][4]=1;
    M.v[1][0] = M.v[2][1] = M.v[3][2] = M.v[4][3] = 1;
    while(tc--){
        int a[5];
        for(int i=0; i<5; i++) cin>>a[i];
        ll d; cin>>d;
        Matrix A;
        A.row = 5; A.col = 1;
        for(int i=0; i<5; i++){
            A.v[i][0] = a[4-i];
        }

        if(d<5){
            cout << a[d] << endl;
            continue;
        }

        Matrix res;
        res.row = 5; res.col = 1;
        res = multiply(power(M,d),A);
        cout << res.v[4][0]%mod << endl;

    }
    return 0;
}

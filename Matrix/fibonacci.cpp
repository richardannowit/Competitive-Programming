//
// Created by richardannowit on 02/12/2020.
//
#include<bits/stdc++.h>
#define MAXN 1000005
#define oo 1000005
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pii pair<ll,ll>
#define max3(a,b,c) max(max(a,b),c)
#define fi first
#define se second
#define RF freopen("input.txt","r",stdin);

using namespace std;

struct matrix {
    ll v[5][5];
    int row, col;
};
ll mod,i,j,k;
matrix multiply(matrix a, matrix b) {
    assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for (i = 0; i < r.row; i++) {
        for (j = 0; j < r.col; j++) {
            ll sum = 0;
            for (k = 0; k < a.col;  k++) {
                sum += (a.v[i][k]%mod)* (b.v[k][j]%mod);
                sum %= mod;
            }
            sum%=mod;
            r.v[i][j] = sum;
        }
    }
    return r;
}

matrix power(matrix mat, int p)
{
    assert(p >= 1);
    if (p == 1) return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

int main() {
    ll a,b,n,m;
    cin>>a>>b>>n>>m;
    matrix mat;
    mat.row = mat.col = 2;
    mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
    mat.v[1][1] = 0;
    mod = 1;
    for (i = 0; i < m; i++) mod *= 10;
    if (n < 3) {
        if (n == 0) cout << a << endl;
        if (n == 1) cout << b << endl;
        if (n == 2) cout << (a+b) % mod << endl;
    } else {
        mat = power(mat, n - 1);
        int ans = b * mat.v[0][0] + a * mat.v[0][1];
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}

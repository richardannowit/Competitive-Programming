/**
 * File  : khoa.cpp
 * Author: Richard Annowit <richardannowit@gmail.com>
 * Date  : 16-05-2020 19:50:08
 */


#include<bits/stdc++.h>
#define MAXN 100
#define oo 1000
#define vi vector<int>
#define vii vector<pair<int,int>>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>

using namespace std;

int t[4*MAXN];
void build(vi a, int v, int tl, int tr){
    if(tl==tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(a,v*2,tl, tm);
    build(a,v*2+1, tm+1, tr);
    t[v] = __gcd(t[v*2],t[v*2+1]);
}

int gcd(int v, int tl, int tr, int l, int r){
    if(l>r || l>tr || r<tl) return 0;
    if(l<=tl && r>=tr) return t[v];
    int tm = (tl+tr)/2;
    int gcdl = gcd(v*2, tl,tm, l, r);
    int gcdr = gcd(v*2+1, tm+1, tr, l, r);
    return __gcd(gcdl, gcdr);
}
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        t[v] = new_val;
        return;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm)
        update(v*2, tl, tm, pos, new_val);
    else update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = __gcd(t[v*2],t[v*2+1]);
}
int main(){
    int n;
    vi a;
    cin>>n;
    for(int i=0; i<n; i++){
        int u; cin>>u;
        a.pb(u);
    }
    build(a,1,0,n-1);
    update(1,0,n-1,2,14);
    cout << gcd(1,0,n-1, 2,n-1);
    return 0;
}

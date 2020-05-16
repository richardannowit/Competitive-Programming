/**
 * File  : kth_zero.cpp
 * Author: Richard Annowit <richardannowit@gmail.com>
 * Date  : 16-05-2020 23:50:08
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


int t[MAXN*4];
void build(vi a, int v,  int tl, int tr){
    if(tl==tr){
        t[v] = a[tl]==0? 1: 0;
        return;
    }
    int tm = (tl+tr)/2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
}

int count_zero(int v, int tl, int tr, int l, int r){
    if(l>r || l>tr || r<tl) return 0;
    if(l<=tl && r>=tr) return t[v];
    int tm = (tl+tr)/2;
    int resl = count_zero(v*2, tl, tm, l, r);
    int resr = count_zero(v*2+1, tm+1, tr, l, r);
    return resl+resr;
}

int kth_zero(int v, int tl, int tr, int k){
    if(t[v]<k) return -1; // Number of zero in v < k
    if(tl==tr) return tl;
    int tm = (tl+tr)/2;
    if(t[v*2]>=k)
        return kth_zero(v*2, tl, tm, k);
    else
        return kth_zero(v*2,tm+1,tr,k-t[v*2]);
}

int main(){
    int n;
    vi a;
    cin>>n;
    for(int i=0; i<n; i++){
        int u; cin>>u;
        a.pb(u);
    }
    build(a, 1, 0, n-1);
    cout << count_zero(1, 0, n-1, 0, 2) << endl;
    cout << kth_zero(1,0,n-1,2);
    return 0;
}

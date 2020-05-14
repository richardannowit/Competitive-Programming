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

pi t[4*MAXN];


pi combine(pi a, pi b){
    if(a.fi>b.fi)
        return a;
    else if(a.fi<b.fi)
        return b;
    return mp(a.fi,a.se+b.se);
}
void build(vi a,int v, int tl, int tr){
    if(tl==tr){
        t[v] = mp(a[tl],1);
        return;
    }
    int tm = (tl+tr)/2;
    build(a, v*2, tl, tm);
    build(a,v*2+1, tm+1, tr);
    t[v] = combine(t[v*2],t[v*2+1]);
}
pi max_query(int v, int tl, int tr, int l, int r){
    if(l>r || l>tr || r<tl) return mp(-oo, 0);
    if(l<=tl && r>=tr) return t[v];
    int tm = (tl+tr)/2;
    pi maxl = max_query(v*2, tl, tm, l, r);
    pi maxr = max_query(v*2+1, tm+1, tr, l, r);
    return combine(maxl, maxr);
}
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        t[v] = mp(new_val,1);
        return;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm)
        update(v*2, tl, tm, pos, new_val);
    else update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = combine(t[v*2],t[v*2+1]);
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
    update(1,0,n-1,4,0);
    pi res = max_query(1, 0, n-1, 0,n-1);
    cout << res.fi << " " << res.se;
    return 0;
}

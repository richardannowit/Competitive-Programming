#include<bits/stdc++.h>
#define MAX_N 500
#define vi vector<int>
#define pb push_back

using namespace std;

int t[4*MAX_N];

void build(vi a, int v, int tl, int tr){
    //if v is the leaf node (v is the index of tree)
    if(tl==tr){
        t[v] = a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(a,v*2,tl,tm);
    build(a,v*2+1,tm+1,tr);
    t[v] = max(t[v*2],t[v*2+1]);
}
int max_query(int v, int tl, int tr, int l, int r){
    if(l>r || l>tr || r<tl) return -1; // if l and r outside of range (tl, tr)
    if(l<=tl && r>=tr) return t[v]; // if tl and tr inside of (l, r)
    int tm = (tl+tr)/2;
    int maxl = max_query(v*2,tl,tm,l,r);
    int maxr = max_query(v*2+1, tm+1, tr, l, r);
    return max(maxl,maxr);
}
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr){
        t[v] = new_val;
        return;
    }
    int tm = (tl+tr)/2;
    if(pos<=tm)
        update(v*2,tl, tm, pos, new_val);
    else update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = max(t[v*2], t[v*2+1]);
}

int main(){
    vi a;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int u; cin>>u;
        a.pb(u);
    }
    build(a,1,0,n-1);
    update(1, 0, n-1, 3, 0);
    cout << max_query(1,0,n-1,0,n-1);
    return 0;
}

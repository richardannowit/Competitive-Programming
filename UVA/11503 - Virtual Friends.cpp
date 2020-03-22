//Disjoint set
#include<bits/stdc++.h>
#define N 100005

using namespace std;



int p[N],r[N],noElementSet[N];
void init(int n){
    for(int i=0; i<n; i++){
        p[i] = i;
        r[i] = 0;
        noElementSet[i] = 1;
    }
}
int findSet(int i){
    if(p[i]!=i) p[i] = findSet(p[i]);
    return p[i];
}
bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}
int unionAndCountSet(int i, int j){
    int x = findSet(i);
    int y = findSet(j);
    if(!isSameSet(i,j)){
        p[y] = x;
        noElementSet[x]+=noElementSet[y];
    }
    return noElementSet[x];
}

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n,cnt=0; cin>>n;
        map<string,int>f;
        init(min(2*n,N));
        while(n--){
            string a,b;
            cin>>a>>b;
            if(f[a]==0){
                f[a] = ++cnt;
            }
            if(f[b]==0) f[b]=++cnt;
            cout << unionAndCountSet(f[a],f[b])<<endl;
        }
    }
    return 0;
}

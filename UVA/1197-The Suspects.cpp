//Disjoint Set
#include<bits/stdc++.h>
#define N 30000

using namespace std;
int p[N], r[N];

void init(int n){
    for(int i=0; i<n; i++){
        p[i] = i;
        r[i] = 0;
    }
}

int findSet(int i){
    if(p[i]==i) return i;
    return findSet(p[i]);
}

bool isSameSet(int i, int j){
    return findSet(i)==findSet(j);
}

void unionSet(int i, int j){
    if(!isSameSet(i,j)){
        int x= findSet(i);
        int y = findSet(j);
        if(r[x]==r[y]) r[x]++;
        if(r[x]>r[y]) p[y] = x;
        else p[x] = y;
    }
}



int main(){
    int n,m;
    while(scanf("%d %d",&n,&m), (n||m)){
        int cnt=0;
        set<int>s;
        s.insert(0);
        init(n+1);
        while(m--){
            int k; cin>>k;
            int prex=-1,x;
            for(int i=0;i<k; i++){
                cin>>x;
                s.insert(x);
                if(i==0){
                    prex = x;
                    continue;
                }
                unionSet(prex,x);
                prex = x;
            }
        }
        for(auto x:s) if(isSameSet(0,x)) cnt++;
        cout << cnt << endl;
    }
    return 0;
}

//KMP
#include<bits/stdc++.h>
#define MAXN 1000005

using namespace std;

int b[MAXN];

int kmpPre(string P){
    int n = P.length();
    int i=0,j=-1,cnt=0;
    b[0] = -1;
    while(i<n){
        while(j>=0 && P[i]!=P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
    return --j;
    
}

int Periodic(string s){
    int n = s.length();  
    int t = kmpPre(s);
    if(n%(n-t-1))
        return n;
    else return n-t-1;
}
int main(){
    int tc; cin>>tc;
    while(tc--){
        string s;
        cin>>s;
        printf("%d\n",Periodic(s));
    }
    return 0;
}

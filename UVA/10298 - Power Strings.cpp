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

int powString(string s){
    int n = s.length();  
    int t = kmpPre(s);
    if(n%(n-t-1))
        return 1;
    else return n/(n-t-1);
}
int main(){
    string s;
    cin>>s;
    while(s!="."){
        
        int n = s.length();
        if(s=="."){
            break;
        }
        printf("%d\n",powString(s));
        cin>>s;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int b[100000];

void kmpPre(string P){
    int i=0,j=1,m= P.length();
    memset(b,0,sizeof(b));
    b[0] = -1;
    while(i<m){
        while(j>=0 && P[i]!=P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

bool kmp(string P, string T){
    int i=0, j=0, n = T.length(), m = P.length();
    if(m>n){
        int tmp = m; m = n; n = tmp;
        string TMP = T; T = P; T = TMP;
    }
    kmpPre(P);
    while(i<n){
        while(j>=0 && T[i]!=P[j]) return false;
        i++; j++;
        if(j==m) return true;
    }
    return false;
}

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n;
        bool flag = true;
        vector<string>st;
        cin>>n; 
        for(int i=0; i<n; i++){
            string s; cin>>s;
            st.push_back(s);
        }
        sort(st.begin(),st.end());
        for(int i=0; i<n-1; i++){
            if(kmp(st[i], st[i+1])){
                flag = false; break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
#include<bits/stdc++.h>
#define MAXN 6
#define oo 1e9
#define ll long long
#define all(x) x.begin(), x.end()

using namespace std;
const ll mod = 1e9+7;


void PreProcess(string s, int pre[]){
    int n = s.length();
    int i=1, j=0;
    pre[0] = 0;
    while(i<n){
        if(s[i]==s[j]){
            j++;
            pre[i] = j;
            i++;
        } else{
            if(j!=0) j = pre[j-1];
            else{
                pre[i] = 0;
                i++;
            }
        }
    }

}
void KMP(string s){
    int len = s.length();
    string ss = s;
    string rs = s;
    reverse(all(rs));
    s = rs+"#"+s;
    int n = s.length();
    int pre[n+5];
    PreProcess(s, pre);
    int max_len = len-pre[n-1];
    string r="";
    for(int i=0; i<max_len; i++){
        r += ss[i];
    }
    reverse(all(r));
    cout << ss + r << endl;

}
int main(){
    //RF;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(!cin.eof()){
        string s; cin>>s;
        KMP(s);
    }

    return 0;
}

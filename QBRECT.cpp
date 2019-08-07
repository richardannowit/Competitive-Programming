#include<bits/stdc++.h>

using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	int m,n,res = -1; cin>>m>>n;
	int h[m+1][n+1];
	memset(h,0,sizeof(h));
	for(int i=1; i<=m; i++){
		vector<int>l(n),r(n);
		deque<int>s;
		for(int j=0; j<n; j++){
			int x; cin>>x;
			x==0?h[i][j]=0:h[i][j] = h[i-1][j]+1;
		}
		for(int j=0; j<n; j++){
			while(!s.empty() && h[i][s.back()]>=h[i][j]) s.pop_back();
			if(s.empty()) l[j] = -1;
			else l[j] = s.back();
			s.push_back(j);
		}
		s.clear();
		for(int j=n-1; j>=0; j--){
			while(!s.empty() && h[i][s.back()]>=h[i][j]) s.pop_back();
			if(s.empty()) r[j] = n;
			else r[j] = s.back();
			s.push_back(j);
		}
		for(int j=0; j<n; j++){
			res = max(res, (r[j]-l[j]-1)*h[i][j]);
		}
	}
	cout << res;
	return 0;
}

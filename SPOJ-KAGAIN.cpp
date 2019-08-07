#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int>a(n),l(n),r(n);
		deque<int>s;
		for(int &x:a) cin>>x;
		for(int i=0; i<n; i++){
			while(!s.empty() && a[s.back()]>=a[i]) s.pop_back();
			if(s.empty()) l[i] = -1;
			else l[i] = s.back();
			s.push_back(i);
		}
		s.clear();
		for(int i=n-1; i>=0; i--){
			while(!s.empty() && a[s.back()]>=a[i]) s.pop_back();
			if(s.empty()) r[i] = n;
			else r[i] = s.back();
			s.push_back(i);
		}
		int max = -1, ii=0;
		for(int i=0; i<n; i++){
			int res = (r[i]-l[i]-1)*a[i];
			if(res>max){
				max = res;
				ii = i;
			}
		}
		cout << (r[ii]-l[ii]-1)*a[ii] << " " << l[ii]+2 << " " << r[ii] << endl;
	}
	return 0;
}

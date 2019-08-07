#include<bits/stdc++.h>

using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	int tc;
	cin>>tc;
	while(tc--){
		int n,k; cin>>n>>k;
		vector<int>a(n);
		for(int &x:a) cin>>x;
		deque<int>s;
		for(int i=0; i<k; i++){
			while(!s.empty() && a[s.back()]>=a[i]) s.pop_back();
			s.push_back(i);
		}
		cout << a[s.front()]<< " ";
		for(int i=k; i<n; i++){
			while(!s.empty() && s.front()<=i-k) s.pop_front();
			while(!s.empty() && a[s.back()]>=a[i]) s.pop_back();
			s.push_back(i);
			cout << a[s.front()]<< " ";
		}
		cout << endl;
	}
	return 0;
}

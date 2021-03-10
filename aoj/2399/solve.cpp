#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
	
	int n,m;
	
	while(cin >> n,n){
		vector<int>v[101];
		for(int i=0;i<n;i++){
			cin >> m;
			int a;
			for(int j=0;j<m;j++){
				cin >> a;
				v[i].push_back(a);
			}
			sort(v[i].begin(),v[i].end());
		}
		int k;
		cin >> k;
		vector<int>l(k);
		for(int i=0;i<k;i++)cin >> l[i];
		
		int ans=0,id=-1;
		for(int i=0;i<n;i++){
			bool fg=true;
			for(int j=0;j<l.size();j++)
				if(!binary_search(v[i].begin(),v[i].end(),l[j]))fg=false;
			if(fg)ans++,id=i;
		}
		if(ans==1)cout << id+1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}

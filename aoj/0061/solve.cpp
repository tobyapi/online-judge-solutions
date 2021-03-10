#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef pair<int,int>pii;

int main(void){

	map<int,int>mp;
	vector<pii>v;
	while(true){
		int a,b;
		scanf("%d,%d",&a,&b);
		if(a==0 && b==0)break;
		v.push_back(pii(b,a));
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());

	int k=1;
	for(int i=0;i<v.size();i++){
		mp[v[i].second]=k;
		if(v[i].first!=v[i+1].first)k++;
	}

	int n;
	while(cin >> n){
		cout << mp[n] << endl;
	}

	return 0;
}

#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(void){
	
	int n,l;
	ll ans=0;
	priority_queue<int,vector<int>,greater<int> >que;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> l;
		que.push(l);
	}
	
	while(que.size()>1){
		int l1,l2;
		l1=que.top(),que.pop();
		l2=que.top(),que.pop();
		ans+=l1+l2;
		que.push(l1+l2);
	}
	
	cout << ans << endl;
	
	return 0;
}
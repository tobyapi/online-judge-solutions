#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main(void){
	
	int n;
	cin >> n;
	string in;
	int x,now=0;
	bool fg=false;
	
	for(int i=0;i<n;i++){
		cin >> in >> x;
		if(in=="(")now+=x;
		else now-=x;
		if(now<0)fg=true;
	}
	if(fg || now>0)cout << "NO" << endl;
	else cout << "YES" << endl;
	
	return 0;
}

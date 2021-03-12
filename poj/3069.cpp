#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
	
	int n,r,x[1000];
	
	while(cin >> r >> n,~r|~n){
		
		for(int i=0;i<n;i++)cin >> x[i];
		sort(x,x+n);
		
		int i=0,ans=0;
		
		while(i<n){
			int s=x[i++];
		
			while(i<n && x[i]<=s+r)i++;
			int p=x[i-1];
			while(i<n && x[i]<=p+r)i++;
			ans++;
		}
	cout << ans << endl;
	}
	
  return 0;
}
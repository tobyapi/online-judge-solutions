#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

	int n;
	while(cin >> n,n){
		int mx=0,a,cnt=0,sum=0;
		for(int i=0;i<n;i++){
			cin >> a,mx=max(mx,a);
			if(mx>=2)cnt++;
			if(a>0)sum++;
		}
		if(mx<2)cout <<"NA"<<endl;
		else if(cnt==1)cout << "2" << endl;
		else cout << sum+1 << endl;
	}

	return 0;
}

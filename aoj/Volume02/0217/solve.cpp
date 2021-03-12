#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

	int n,a,d1,d2,ans,dist;
	
	while(cin >> n,n){
		ans=0,dist=0;
		for(int i=0;i<n;i++){
			cin >> a >> d1 >> d2;
			if(d1+d2>dist)ans=a,dist=d1+d2;
		}
	
		cout << ans <<" "<< dist << endl;
	}
	
return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

	vector<int>v(21);
	for(int i=1;i<21;i++){
		cin >> v[i];
	}
	v[0]=0;

	vector<int> tmp=v;
	tmp=v;
	int ans=(1<<29);
	for(int k=0;k<2;k++){
		v=tmp;
		v[0]=k;
		int cnt=0;
		for(int i=0;i<20;i++){
			if(v[i]==1){
				cnt++;
				for(int j=0;j<3 && i+j<21;j++){
					v[i+j]=v[i+j]?0:1;
				}
			}
		}
		ans=min(ans,cnt);
	}

	cout << ans << endl;

	return 0;
}
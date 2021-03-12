#include<iostream>
#include<vector>

using namespace std;

typedef unsigned int uint;

uint xor128(void) { 
  static uint x = 123456789;
  static uint y = 362436069;
  static uint z = 521288629;
  static uint w = 88675123; 
  uint t;
 
  t=x^(x<<11);
  x=y; y=z; z=w;
  return w=(w^(w>>19))^(t^(t>>8)); 
}

int n,k,ans[1001],card[501][1001];
	
bool ok(void){

	for(int i=0;i<k;i++){
		int sum=0;
		for(int j=0;j<n/2;j++)sum+=ans[card[i][j]-1];
		
		if(sum<n/8 || 3*n/8<sum)return false;
	}
	return true;
}

int main(void){
	
	cin >> n >> k;
	
	for(int i=0;i<k;i++){
		for(int j=0;j<n/2;j++){
			cin >> card[i][j];
		}
	}
	
	while(true){
		for(int j=0;j<n;j++)ans[j]=xor128()%2;
		
		if(ok()){
			for(int j=0;j<n;j++)cout << ans[j];
			cout << endl;
			break;
		}
	}
	
return 0;
}

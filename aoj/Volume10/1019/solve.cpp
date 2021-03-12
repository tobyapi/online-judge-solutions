#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  int n,k,s[100],b;

  while(cin >> n >> k,n|k){
    for(int i=0;i<k;i++)cin >> s[i];
    
    for(int i=0;i<n;i++){
      for(int j=0;j<k;j++){
	cin >> b;
	s[j]-=b;
      }
    }
    
    bool fg=false;
    for(int i=0;i<k;i++){
      if(s[i]<0){
	cout << "No" << endl;
	fg=true;
	break;
      }
    }
    if(!fg)cout << "Yes" << endl;
  }

  return 0;
}

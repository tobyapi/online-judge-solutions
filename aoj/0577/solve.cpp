#include<iostream>

using namespace std;

int main(void){

  int n,p[3][200],ans[200];
  bool fg[3][200];

  
  
  while(cin >> n){

      for(int i=0;i<n;i++){
	ans[i]=0;
	for(int j=0;j<3;j++){
	  cin >> p[j][i];
	  fg[j][i]=false;
	}
      }

    
    for(int i=0;i<3;i++){
      for(int j=0;j<n;j++){
	for(int k=0;k<n;k++){
	  if(j!=k && p[i][j]==p[i][k]){
	    fg[i][j]=fg[i][k]=true;
	    break;
	  }
	}
      }
    }
    
    for(int i=0;i<3;i++){
      for(int j=0;j<n;j++){
	if(fg[i][j]==false){
	  ans[j]+=p[i][j];
	}
      }
    }


    for(int i=0;i<n;i++){
      cout << ans[i] << endl;
    }
  }

  return 0;
}

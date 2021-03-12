#include<iostream>
#include<cstdio>

using namespace std;

int dp[101][101][5],w,h;

int func(int i, int j, int p){
  if(i>w || j>h)return 0;
  if(i==w && j==h)return 1;
  if(dp[i][j][p]>0)return dp[i][j][p];

  int res=0;
  if(p==1)res=func(i,j+1,3);
  else if(p==2)res=func(i+1,j,4);
  else if(p==3)res=func(i+1,j,2)+func(i,j+1,3); 
  else if(p==4)res=func(i+1,j,4)+func(i,j+1,1);
  else if(p==0)res=func(i,j+1,3)+func(i+1,j,4);

  return dp[i][j][p]=res%100000;
}

int main(void){

  while(cin >> w >> h,w|h){
    for(int i=0;i<=w;i++)
      for(int j=0;j<=h;j++)
	for(int p=0;p<5;p++)
	dp[i][j][p]=0;

    cout << func(1,1,0) << endl;
  }

  return 0;
}

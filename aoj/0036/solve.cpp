#include<iostream>
#include<cstdio>

using namespace std;

int A[7][4][4]={
  
  {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  },
  
  {
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
  },
  
  {
    {1,1,1,1},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
  },
  
  {
    {0,1,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {0,0,0,0},
  },
  
  {
    {1,1,0,0},
    {0,1,1,0},
    {0,0,0,0},
    {0,0,0,0},
  },
  
  {
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,0,0,0},
  },
  
  {
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  },
},
  
  a[12][12];

string s="ABCDEFG";

bool check(int x, int y, int n){
  
  for(int k=0;k<4;k++){
    for(int l=0;l<4;l++){
      int nx=x+k,ny=y+l;
      if(A[n][k][l]==1){
	if(a[nx][ny]!=A[n][k][l]){
	  return false;
	}
	if(nx<0||nx>7||ny<0||ny>7){
	  return false;
	}
      }
    }
  }
  return true;
}


int main(void){

  char ch;

  while(true){

    for(int i=0;i<12;i++)
      for(int j=0;j<12;j++)
	a[i][j]=0;
    
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
	if(scanf(" %c",&ch)==EOF)return 0;
	a[i][j]=ch-'0';
      }
    }
    bool fg=true;
    for(int k=0;fg && k<7;k++){
      for(int i=0;fg && i<8;i++){
	for(int j=0;fg && j<8;j++){
	  if(check(i,j,k)){
	    cout << s[k] << endl;
	    fg=false;
	  }
	}
      }
    }
  }

  return 0;
}

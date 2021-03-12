#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int g[16][16],n,x,y,now;

void func2(void);

void func1(void){
  if(x>=n)x=0;
  if(x<0)x=n-1;
  if(y>=n)y=0;

  if(g[y][x]>0)func2();
}

void func2(void){
  if(g[y][x]>0) x--,y++;
  if(x>=n || x<0 || y>=n)func1();
}

int main(void){

  while(cin >> n,n){
    for(int i=0;i<16;i++)
      for(int j=0;j<16;j++)
	g[i][j]=0;

      x=n/2;
      y=n/2+1;
    g[y][x]=1;

    now=2;

    for(int i=1;i<n*n;i++,now++){
      x++;
      y++;
      if(x>=n || x<0 || y>=n)func1();
	 if(g[y][x]>0)func2();
	 g[y][x]=now;
    }

      for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  printf("%4d",g[i][j]);
	}
	cout << endl;
      }
    }
    
  return 0;
}

#include<iostream>
#include<algorithm>

using namespace std;

short max(int a,int b){
  return a>b?a:b;
}

short nails[5001][5001];

int main(void){

  int n,m,a,b,x;
 
  cin >> n >> m;

  for(int i=0;i<m;i++){
    cin >> a >> b >> x;
    nails[a][b]=x+1;
  }

  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      nails[i][j]=max(nails[i][j],max(nails[i-1][j-1],nails[i-1][j])-1);      

  int cnt=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
      if(nails[i][j]>0)cnt++;
     
  cout << cnt << endl;

  return 0;
}

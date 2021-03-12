#include<iostream>
#include<cstdio>

using namespace std;

struct P{int i,j;};

int a[300][300],b[100][100],c[100][100],n,m;


P ok(void){
  P res;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int fg=0;
      res.i=res.j=1000;
      for(int k=0;k<m;k++){
	for(int l=0;l<m;l++){
	  if(c[k][l]>=0 && a[i+k][j+l]!=c[k][l]){
	    fg=1;
	    break;
	  }
	}
	if(fg==1)break;
      }
      if(fg==0){
	for(int k=0;k<m;k++){
	  for(int l=0;l<m;l++){
	    if(c[k][l]>=0){
	      res.i=k+i;
	      res.j=l+j;
	      return res;
	    }
	  }
	}
      }
    }
  }
  return res;
}

int main(void){

  while(cin >> n >> m,n|m){

    for(int i=0;i<100;i++)
      for(int j=0;j<100;j++)
	b[i][j]=c[i][j]=-1;

    for(int i=0;i<300;i++)
      for(int j=0;j<300;j++)
	a[i][j]=-2;

    P res,ans;
    res.i=res.j=ans.i=ans.j=1000;

    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
	cin >> a[i][j];
    
    for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
	cin >> b[i][j];

    for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
	c[i][j]=b[i][j];

    res=ok();
    if(ans.i>res.i)ans=res;
    else if(ans.i==res.i && ans.j>res.j)ans=res;
    
    for(int i=m-1;i>=0;i--)
      for(int j=0;j<m;j++)
	c[j][m-i-1]=b[i][j];
    
    res=ok();
    if(ans.i>res.i)ans=res;	
    else if(ans.i==res.i && ans.j>res.j)ans=res;

    for(int i=m-1;i>=0;i--)
      for(int j=m-1;j>=0;j--)
	c[m-i-1][m-j-1]=b[i][j];

    res=ok();
    if(ans.i>res.i)ans=res;
    else if(ans.i==res.i && ans.j>res.j)ans=res;

    for(int i=0;i<m;i++)
      for(int j=m-1;j>=0;j--)
	c[m-j-1][i]=b[i][j];
    
    res=ok();
    if(ans.i>res.i)ans=res;
    else if(ans.i==res.i && ans.j>res.j)ans=res;

    if(ans.i<1000)cout << ans.j <<" "<<ans.i << endl;
    else cout << "NA" << endl;
  }

  return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

char g[1010][1010],pat[5][5];
int h,w;
string ch="JOI";

bool match(int x, int y){
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      if(g[y+i][x+j]!=pat[i][j])return false;
    }
  }
  return true;
}

int count(int x, int y) {
  int res=0;
  for(int i=-1;i<1;i++){
    for(int j=-1;j<1;j++){
      int nx=x+j,ny=y+i;
      if(nx>=0 && ny>=0 && match(nx,ny))res++;
    }
  }
  return res;
}


int solve() {
  
  int res=0;

   for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(match(j,i))res++;
    }
  }
   
   int mx=res;
   for(int i=0;i<h;i++){    
     for(int j=0;j<w;j++){
       char tmp=g[i][j];

       int c=count(j,i);
       for(int k=0;k<3;k++){
	 g[i][j]=ch[k];
	 mx = max(mx,res-c+count(j,i));
       }

       g[i][j]=tmp;
     }
   }
   return mx;
}

int main(void){

  cin >> h >> w;
  
  fill(g[0],g[1010],NULL);
  fill(pat[0],pat[5],NULL);

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> g[i][j];
    }
  }

  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      cin >> pat[i][j];
    }
  }
  
  cout << solve() << endl;

  return 0;
}

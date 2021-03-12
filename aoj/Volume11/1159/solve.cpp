#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

  int n,p,a[51];

bool check(int x){
  for(int i=0;i<n;i++)if(a[i]>0 && i!=x)return false;
  return true;
}

int main(void){

  while(cin >> n >> p,n|p){
    fill(a,a+51,0);

    for(int i=0;i<1000001;i++){

      if(p>0)p--,a[i%n]++;
      else if(p==0 ){
	if(check(i%n)){
	  cout << i%n << endl;
	  break;
	}
	p=a[i%n],a[i%n]=0;
      }
    }
  }

  return 0;
}

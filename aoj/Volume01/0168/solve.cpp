#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

  int n,a[31];

  fill(a,a+31,0);
  a[0]=a[1]=1,a[2]=2;

  for(int i=3;i<31;i++)
    for(int j=1;j<4;j++)
      a[i]+=a[i-j];
  
  while(cin >> n,n){
    int m=!(a[n]%365>0)?:1;
    cout << a[n]/3650+m << endl;
  }

  return 0;
}

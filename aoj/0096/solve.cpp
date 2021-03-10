#include<iostream>
#include<vector>
#include<algorithm>

#define all(a) (a).begin(),(a).end()

using namespace std;

int c[2001],res[4001];

int main(void){

  for(int i=0;i<1001;i++)
    for(int j=0;j<1001;j++)
      c[i+j]++;

  for(int i=0;i<2001;i++)
    for(int j=0;j<2001;j++)
      res[i+j]+=c[i]*c[j];

  int n;
  while(cin >> n)cout << res[n] << endl; 
  

  return 0;
}

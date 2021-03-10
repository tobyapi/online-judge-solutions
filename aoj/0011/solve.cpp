#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
  int x,y,a,b,n[30];
  char s;

  cin >> y >> x;
  for(int i=0;i<y;i++)n[i]=i+1;

  for(int i=0;i<x;i++){
    cin >> a >> s >> b;
    swap(n[a-1],n[b-1]);
  }
  for(int i=0;i<y;i++)cout << n[i] << endl;

  return 0;
}

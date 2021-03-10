#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
  int a,b,c;
  cin >> a >> b >> c;

  for(int i=0;;i+=a+b){
    if(i<=c && c<=i+a){
      cout << i+c%60-i%60 << endl;
      break;
    }
    //if(60<i && 60%(a+b)==0){
    if(100000<i){
      cout << -1 << endl;
      break;
    }
    if(i/60 != (i+a+b)/60)c+=60;
  }
  
  return 0;
}

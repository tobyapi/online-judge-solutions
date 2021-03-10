#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

  int c1,c2,c3;
  while(cin >> c1 >> c2 >> c3){
    double p=0;

    for(int i=1;i<=10;i++){
      if(i==c1 || i==c2 || i==c3)continue;
      if(c1+c2+i<=20)p+=(double)1/(double)7;
    }
    
    if(p>=0.5)cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}

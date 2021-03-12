#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

  int n,pm,pe,pj;

  while(cin >> n,n){
    while(n--){
      cin >> pm >> pe >> pj;
      
      int ave=(pm+pe+pj)/3;
      
      if((pm==100 || pe==100 || pj==100)||(pm+pe)/2 >=90 || ave>=80){
	cout << "A" << endl;
	continue;
      }
      
      if(ave>=70 || (ave>=50 && (pm>=80 || pe>=80))){
	cout << "B" << endl;
	continue;
      }
      
      cout << "C" << endl;
    }
  }
  
  return 0;
}

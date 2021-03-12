#include<iostream>
#include<cmath>
#include<algorithm>
 
using namespace std;
 
int main(void){
 
  int a,b,c,res[4]={};
 
  while(cin >> a >> b >> c){
    
    if(a+b<=c || a+c<=b || b+c<=a){

      for(int i=0;i<4;i++){
	cout << res[i];
	if(i<3)cout <<" ";
      }
      cout <<endl;
      break;
    }
    
    res[0]++;
    if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)res[1]++;
    else if(a*a+b*b>=c*c && a*a+c*c>=b*b && b*b+c*c>=a*a)res[2]++;
    else res[3]++;
  } 
  return 0;
}

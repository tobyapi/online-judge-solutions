#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
  
using namespace std;
  
void extgcd(int a,int b,int &x,int &y){
x=1,y=0;
  if(b!=0)extgcd(b,a% b,y,x),y-=(a/b)*x; 
}
  
int main(void){
  
  int a,b;
  
  cin >> a >> b;
  
int x,y;
  extgcd(a,b,x,y);
  cout << x << " " << y << endl;
  
  return 0;
}

#include<iostream>

using namespace std;

int main(void){
  int sum,a,b,i,j;
  string clas;

  while(cin>> clas >> a >> b){
    cout << clas <<" "<< a+b << " " << 200*a+300*b << endl;
}

  return 0;
}

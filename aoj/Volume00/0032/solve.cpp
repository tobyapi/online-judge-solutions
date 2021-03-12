#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
  int a,b,c,count1=0,count2=0;
  
  while(scanf("%d,%d,%d",&a,&b,&c)!=EOF){
    if(c*c==a*a+b*b && (a!=b && b!=c))count1++;
    else if((a==b&&b!=c) || (a==b && b==c))count2++;
  }
  cout << count1 <<"\n"<< count2 << endl;
  
  return 0;
}

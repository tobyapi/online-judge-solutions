#include<iostream>
#include<string>
 
using namespace std;

class Dice{

private:

  int top,front,right,left,back,bottom;

public:

  Dice(){
    top=1;
    front=2;
    right=3;
    left=4;
    back=5;
    bottom=6;
  }

 
int North(void){
  int t;
  t=top,top=front,front=bottom,bottom=back,back=t;
  return top;
}
 
int East(void){
  int t;
  t=top,top=left,left=bottom,bottom=right,right=t;
  return top;
}
 
int West(void){
  int t;
  t=top,top=right,right=bottom,bottom=left,left=t;
  return top;
}
 
int South(void){
  int t;
  t=top,top=back,back=bottom,bottom=front,front=t;
  return top;
}
 
int Right(void){
  int t;
  t=front,front=right,right=back,back=left,left=t;
  return top;
}
 
int Left(void){
  int t;
  t=front,front=left,left=back,back=right,right=t;
  return top;
}

};


int main(void){
  int n,sum;
  string s;
   
  while(cin >> n,n){
 
    Dice *d = new Dice();
    sum=1;
 
    for(int i=0;i<n;i++){
      cin >>s;
      if(s=="North")sum+=d->North();
      else if(s=="East")sum+=d->East();
      else if(s=="South")sum+=d->South();
      else if(s=="West")sum+=d->West();
      else if(s=="Left")sum+=d->Left();
      else if(s=="Right")sum+=d->Right();

    }
    cout << sum << endl;
  }

  return 0;
}

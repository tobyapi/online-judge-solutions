#include<iostream>
#include<string>

using namespace std;

class Dice{

private:

  int top,front,right,left,back,bottom;

public:

  Dice(){
    top=1;
    front=5;
    right=4;
    left=3;
    back=2;
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

  int getTop(void){
    return top;
  }

};


int main(void){
  int n;
  string s;

  while(cin >> n,n){

    Dice *d = new Dice();

    for(int i=0;i<n;i++){
      cin >>s;
      if(s=="north")d->North();
      else if(s=="east")d->East();
      else if(s=="south")d->South();
      else if(s=="west")d->West();
    }
    cout <<  d->getTop() << endl;
  }

  return 0;
}

#include<iostream>
#include<string>

using namespace std;


int calc(int x,string op,int y){
  if(op=="+")return x+y;
  else if(op=="-")return x-y;
  else if(op=="*")return x*y;
  else if(op=="/")return x/y;
}

int main(void){

  int x,y;
  string op;

  cin >> x;

  while(true){

    cin >> op;

    if(op=="="){
      cout << x << endl;
      break;
    }

    cin >> y;
   x=calc(x,op,y);
  }

  return 0;
}

#include<iostream>

using namespace std;

int main(void){
  int n;

  while(cin >> n){
    int cnt=0;
    for(int a=0;a<10;a++)
      for(int b=0;b<10;b++)
	for(int c=0;c<10;c++)
	  for(int d=0;d<10;d++)
	    if(a+b+c+d==n)cnt++;

    cout << cnt << endl;
  }


  return 0;
}

#include<iostream>

using namespace std;

int main(void){
  int k,c,sum,i;

  while(1){
    sum=0;
    cin >> k;

    if(k==0)break;

    for(i=0;i<(k*(k-1))/2;i++){
      cin>>c;
      sum+=c;

  }

  
cout << sum/(k-1)<<endl;
}


  return 0;
}

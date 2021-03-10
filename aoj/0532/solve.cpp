#include<iostream>

using namespace std;

void calc(int *b,int *e){
  int res[3];
  for(int i=0;i<3;i++)res[i]=e[i]-b[i];
  for(int i=2;i>0;i--)
    if(res[i]<0)res[i-1]--,res[i]+=60;
  
  cout << res[0] << " " << res[1] << " " << res[2] << endl;
}

int main(void){
  int b[3],e[3];

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)cin >> b[j];
    for(int j=0;j<3;j++)cin >> e[j];
    calc(b,e);
  }
  
  return 0;
}

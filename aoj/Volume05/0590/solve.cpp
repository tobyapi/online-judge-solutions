#include<iostream>
#include<cmath>

using namespace std;

bool is_room(int S){

  for(int i=1;i*i<=S;i++)
    if((S-i)%(2*i+1)==0)return true;
  return false;
}

int main(void){

  int n,S,cnt=0;

  cin >> n;
  while(n--){
    cin >> S;
    if(!is_room(S))cnt++;
  }
  cout << cnt << endl;

  return 0;
}

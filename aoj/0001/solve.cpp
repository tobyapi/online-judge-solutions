#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  int h;
  vector<int>hill;

  for(int i=0;i<10;i++){
    cin >> h;
    hill.push_back(h);
  }

  sort(hill.begin(),hill.end(),greater<int>());

  for(int i=0;i<3;i++)
    cout << hill[i] << endl;

  return 0;
}

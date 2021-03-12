#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<set>

using namespace std;

int main(void){

  int n;
  cin >> n;
  set<string>S;

  for(int i=0;i<n;i++){
    string in;
    cin >> in;
    S.insert(in);
  }

  bool now=false;
  cin >> n;
  for(int i=0;i<n;i++){
    string in;
    cin >> in;
    if(!S.count(in))cout << "Unknown " << in << endl;
    else if(!now)cout << "Opened by " << in << endl,now=!now;
    else if(now)cout << "Closed by " << in << endl,now=!now;
  }

  return 0;
}

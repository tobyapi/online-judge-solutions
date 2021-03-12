#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  string s;
  vector<int>num;
  while(cin >> s){
    num.clear();
    for(int i=0;i<10;i++)
      num.push_back(s[i]-'0');
    
    vector<int>n;
    for(int i=0;i<9;i++){
      for(int j=0;j<num.size()-1;j++){
	n.push_back((num[j]+num[j+1])%10);
      }
      num=n;
      n.clear();
    }
    cout << num[0] << endl;
  }
  return 0;
}

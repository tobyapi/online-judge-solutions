#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
  string s;
  int ans=0;
  while(cin >> s){
    int cnt=0;
    for(int i=0;i<s.size()/2;i++)
      if(s[i]==s[s.size()-i-1])cnt++;

    if(cnt==s.size()/2)ans++;
  }
  cout << ans << endl;

  return 0;
}

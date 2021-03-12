#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<climits>

using namespace std;


int main(void){
  string s;

  while(cin >> s){
    int cnt=0;
    for(int i=0;i<s.size()/2;i++){
      if((s[i]=='i' && s[s.size()-i-1]!='i')||
	 (s[i]=='w' && s[s.size()-i-1]!='w')||
	 (s[i]=='(' && s[s.size()-i-1]!=')')||
	 (s[i]==')' && s[s.size()-i-1]!='('))cnt++;
    }
    if(s.size()%2 && !(s[s.size()/2]=='i'||s[s.size()/2]=='w'))cnt++;
    cout << cnt << endl;
  }
  
  return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int now;
string s;

int number(){
  int res=0;
  while('0'<=s[now] && s[now]<='9')
    res*=10,res+=s[now++]-'0';
  return res/2+1;
}

int factor(){
  
  if(s[now]=='['){
    vector<int>v;
    while(s[now]=='['){
      now++;
      v.push_back(factor());
      now++;
    }
    sort(v.begin(),v.end());
    int res=0;
    for(int i=0;i<v.size()/2+1;i++)res+=v[i];
    return res;
  }
  return number();
}

int main(void){
  
  int n;
  cin >> n;

  while(n--){
    now=0;
    cin >> s;
    cout << factor() << endl;
  }

  return 0;
}

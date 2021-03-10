#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

string toString(int a){
  ostringstream oss;
  oss << a;
  return oss.str();
}

int toInt(string s){
  istringstream iss(s);
  int a;
  iss >> a;
  return a;
}

int main(){
  vector<int> r;
  int t[10010] = {};
  int n, a;
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    scanf("%d", &a);
    r.push_back(a);
    t[a]++;
  }

  int tt[10010];
  for(int i = 0 ; i < 10010 ; i++){
    tt[i] = t[i];
  }
  
  vector<int> v;
  
  for(int i = 1 ; i <= 10000 ; i++){
    while(t[i] > 0){
      v.push_back(i);
      t[i]--;
      if(v.size() == 10) break;
    }
    if(v.size() == 10) break;
  }

  vector<int> v2;
  
  for(int i = 0 ; i < v.size() ; i++){
    for(int j = 0 ; j < v.size() ; j++){
      if(i == j) continue;
      string s1="", s2="", s="";
      s1 = toString(v[i]);
      s2 = toString(v[j]);
      s = s1 + s2;
      int b = toInt(s);
      v2.push_back(b);
    }
  }
  
  sort(v2.begin(), v2.end());
  
  cout << v2[2] << endl;
  return 0;
}

  

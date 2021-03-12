#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> func(vector<int> s){
  vector<int>t;
  for(int i=0;i<s.size();i++){
    int cnt=0;
    for(int j=0;j<s.size();j++){
      if(s[i]==s[j])cnt++;
    }
    t.push_back(cnt);
  }
  return t;
}

int main(void){
  vector<int>p;
  int n,x;
  
  while(cin >> n,n){
    p.clear();
    for(int i=0;i<n;i++){
      cin >> x;
      p.push_back(x);
    }
    
    int cnt=0;
    while(true){
      vector<int>res=func(p);
      if(res==p){
	cout << cnt << endl;
	for(int i=0;i<res.size();i++){
	  cout << res[i];
	  if(i==res.size()-1)cout << endl;
	  else cout <<" ";
	}
	break;
      }
      p=res;
      cnt++;
    }
  }
  return 0;
}

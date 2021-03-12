#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

void func(int n, int m, vector<int>res){

  if(n==0){
    for(int i=0;i<res.size();i++){
      cout << res[i];
      if(i==res.size()-1)cout << endl;
      else cout << " ";
    }
    return;
  }
  
  for(int i=m;i>0;i--){
    if(i>n)continue;
    res.push_back(i);
    func(n-i,i,res);
    res.pop_back();
  }
}

int main(void){

  int n;
  vector<int>res;

  while(cin >> n,n)
    func(n,n,res);

  return 0;
}

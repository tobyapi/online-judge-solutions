#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main(void){
  string n;
  map<char,int>m;
  m['I']=1;
  m['V']=5;
  m['X']=10;
  m['L']=50;
  m['C']=100;
  m['D']=500;
  m['M']=1000;

  while(cin >> n){
    int cnt=0;
    for(int i=0;i<n.size();i++)cnt+=m[n[i]];
    for(int i=0;i<n.size();i++)
      if(m[n[i]]<m[n[i+1]])cnt-=2*m[n[i]];
    cout << cnt << endl;
  }

  return 0;
}

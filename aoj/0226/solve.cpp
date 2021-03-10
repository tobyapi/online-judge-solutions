#include<iostream>
#include<string>

using namespace std;

int hit(string r,string a){
  int cnt=0;
  for(int i=0;i<r.size();i++)
    if(r[i]==a[i])cnt++;

  return cnt;
}

int blow(string r,string a){
  int cnt=0;
  for(int i=0;i<a.size();i++)
    for(int j=0;j<r.size();j++)
      if(i!=j && a[i]==r[j])cnt++;

  return cnt;
}

int main(void){
  string r,a;

  while(cin >> r >> a){
    if(r=="0" && a=="0")break;
    
    cout << hit(r,a) <<" "<< blow(r,a) << endl;
  }
  return 0;
}

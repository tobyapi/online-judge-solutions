#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
 
using namespace std;
 
int main(void){
  int n;
  string s;
  map<string,int>mp;
 
  while(cin >> n,n){
    mp.clear();
    cin.ignore();
    while(n--){
      getline(cin,s);
      string temp;
      for(int i=0;i<s.size();i++){
    if(s[i]==' '){
      mp[temp]++;
      temp.clear();
      i++;
    }
    else if(i==s.size()-1){
      temp+=s[i];
      mp[temp]++;
      temp.clear();
      i++;
    }
    temp+=s[i];
      }
    }
    char ch;
    cin >> ch;
    int mx=0;
 
    int cnt=0;
  
      for(map<string,int>::iterator i=mp.begin();i!=mp.end();i++){
    string tmp=i->first;
    if(tmp[0]==ch)cnt++;
      }
 
      if(cnt==0){
    cout << "NA" << endl;
    continue;
      }
 
      cnt = cnt>5?5:cnt;
    while(cnt--){
      mx=0;
      for(map<string,int>::iterator i=mp.begin();i!=mp.end();i++){
    string t=i->first;
    if(t[0]==ch)mx=max(i->second,mx);
      }
       
      for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
     
     
    string tmp=it->first;
    if(it->second==mx && tmp[0]==ch){
      cout << it->first;
      if(cnt==0)cout << endl;
      else cout << " ";
      it->second=-1;
      break;
    }
      }
    }
  }
   
  return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

#define all(c) (c).begin(),(c).end()

using namespace std;

void J(string &s){
  string a="";
  a+=s.substr(1,s.size()-1);
  a+=s[0];
  s=a;
}

void C(string &s){
  string a="";
  a+=s[s.size()-1];
  a+=s.substr(0,s.size()-1);
  s=a;
}

void E(string &s){
  string a="";
  if(s.size()%2==1){
    a+=s.substr(s.size()/2+1,s.size()/2);
    a+=s[s.size()/2];
    a+=s.substr(0,s.size()/2);
  }
  else {
    a+=s.substr(s.size()/2,s.size()/2);
    a+=s.substr(0,s.size()/2);
  }
  s=a;
}

void A(string &s){
  reverse(all(s));
}

void P(string &s){
  for(int i=0;i<s.size();i++){
    if(s[i]=='9')s[i]='0';
    else if(isdigit(s[i]))s[i]++;
  }
}

void M(string &s){
  for(int i=0;i<s.size();i++){
    if(s[i]=='0')s[i]='9';
    else if(isdigit(s[i]))s[i]--;
  }
}

int main(void){
  int n;
  string s,com;
  cin >> n;
  while(n--){
    cin >> com >> s;
    A(com);
    for(int i=0;i<com.size();i++){
      if(com[i]=='J')C(s);
      else if(com[i]=='C')J(s);
      else if(com[i]=='E')E(s);
      else if(com[i]=='A')A(s);
      else if(com[i]=='P')M(s);
      else P(s);
    }
    cout << s << endl;
  }
  
  
  return 0;
}

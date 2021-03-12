#include<iostream>
#include<stack>
using namespace std;

int main(void){
  string str;

  while(getline(cin,str) && str!="."){
    string c;
    for(int i=0;i<str.size();i++)
      if(str[i]==')' ||str[i]=='(' ||str[i]=='[' ||str[i]==']')
	c += str[i];

  stack<char> s;
  bool f=true;
    for(int i=0;i<c.length();i++){
      if(s.empty() || c[i]=='(' || c[i]=='[')s.push(c[i]);
      else if((s.top()=='(' && c[i]==')' )||(s.top()=='[' && c[i]==']')){
	s.pop();
      }else{
	f=false;
	break;
      }
      
    }
    cout << (f && s.empty()?"yes":"no") << endl;
  }
  return 0;
}

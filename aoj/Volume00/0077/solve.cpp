#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
  
  vector<char>v;
  string s;
  
  while(getline(cin,s)){
    v.clear();
    for(int i=0;i<s.size();i++){
      if(s[i]=='@'){
	for(int j=0;j<s[i+1]-'0';j++){
	  v.push_back(s[i+2]);
	}
	i+=2;
      }
      else v.push_back(s[i]);
    }
    for(int i=0;i<v.size();i++)cout << v[i];
    cout << endl;  
  }
  return 0;
}

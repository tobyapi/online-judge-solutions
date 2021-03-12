#include<iostream>
#include<string>
#include<cstdio>
#include<cctype>

typedef unsigned long long ull;
const ull B = 100000007;

using namespace std;

bool contain(string,string);

int main(void){
  string str;
  while(getline(cin,str)){
   
    while(1){
	int fg=0;
      for(int j=0;j<26;j++){
	for(int i=0;i<str.length();i++)
	  if(isalpha(str[i]))str[i] = (str[i]=='z')? 'a' : str[i] + 1;

	if(contain("that",str)||contain("the",str)||contain("this",str)){
	  cout << str << endl;
	  fg=1;
	  break;
	}
      }
      if(fg)break;
    }
  }
  return 0;
}

bool contain(string a,string b){
  int al=a.length(),bl=b.length();
  if(al>bl)return false;

  ull t=1;
  for(int i=0;i<al;i++)t*=B;

  ull ah=0,bh=0;
  for(int i=0;i<al;i++)ah=ah*B+a[i];
  for(int i=0;i<al;i++)bh=bh*B+b[i];

  for(int i=0;i+al<=bl;i++){
    if(ah==bh)return true;
    if(i+al<bl) bh=bh*B+b[i+al]-b[i]*t;
  }
  return false;
}

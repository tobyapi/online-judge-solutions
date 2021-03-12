#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cctype>

using namespace std;

typedef unsigned long long ull;
const ull B = 100000007;

bool Rabin_Karp(string a, string b){

  int al = a.length(),bl = b.length();  
  if(al>bl)return false;

  ull t=1;
  for(int i=0; i<al; i++)t*=B;

  ull ah=0,bh=0;
  for(int i=0; i<al; i++)ah=ah*B+a[i];
  for(int i=0; i<al; i++)bh=bh*B+b[i];

  for(int i=0; i+al<=bl; i++){
    if(ah==bh)return true;
    if(i+al<bl)bh=bh*B+b[i+al]-b[i]*t;
  }
  return false;
}

int gcd(int a, int b){
  if(b==0)return a;
  return gcd(b,a%b);
}

char decode(char r, int a, int b)
{
    if ('a'<=r && r<='z') {
        int t = (r-'a') - b;
        while (t%a != 0) t += 26;
        return (t/a) % 26 + 'a';
    } 
    else return r;
}


int main(void){
  int n;
  string str;

  cin >> n;
  cin.ignore();

  while(n--){
    getline(cin,str);
    bool fg=false;
    for(int a=1;a<100;a++){
      if(gcd(a,26)==1){
	for(int b=1;b<100;b++){
	  string res="";
	  for(int k=0;k<str.size();k++)
	    res+=decode(str[k],a,b);
	  
	  if(Rabin_Karp("that",res)||Rabin_Karp("this",res)){
	    cout << res << endl;
	    fg=true;
	    break;
	  }
	}
      }
      if(fg)break;
    }
    
  }

  return 0;
}

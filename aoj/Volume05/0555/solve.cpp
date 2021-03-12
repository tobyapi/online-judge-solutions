#include<iostream>
#include<string>

typedef unsigned long long ull;

const ull B=100000007;

using namespace std;

int RabinKarp(string,string);

int main(void){
  string a,b;
  int n,count=0;

  getline(cin,a);
    cin >> n;
    cin.ignore();
    
    for(int i=0;i<n;i++){
    getline(cin,b); 
    b+=b;
    count+=RabinKarp(a,b);
    }
    
    cout << count << endl;

  return 0;
}

int RabinKarp(string a,string b){
  int al=a.size(),bl=b.size();

  ull t=1;
  for(int i=0;i<al;i++)t*=B;

  ull ah=0,bh=0;

  for(int i=0;i<al;i++){
    ah=ah*B+a[i];
    bh=bh*B+b[i];
  }
  
  for(int i=0;i+al<=bl;i++){
    if(ah==bh)return 1;
    if(i+al<bl)bh=bh*B+b[i+al]-b[i]*t;
  }
  return 0;
}

#include<iostream>
#include<string>

typedef unsigned long long ull;

const ull B=100000007;

using namespace  std;

void RabinKarp(string,string,string);

char ap[]="apple",pe[]="peach";
string str;

int main(void){
  getline(cin,str);
  RabinKarp("apple","peach",str);
  cout << str << endl;
}

void RabinKarp(string a,string b,string c){
  int al=a.size(),bl=b.size(),cl=c.size();

  ull t=1;
  for(int i=0;i<al;i++)t*=B;

  ull ah=0,bh=0,ch=0;
  for(int i=0;i<al;i++){
    ah=ah*B+a[i];
    bh=bh*B+b[i];
    ch=ch*B+c[i];
  }

  for(int i=0;i+al<=cl;i++){
    if(ah==ch)for(int j=i;j<i+al;j++)str[j]=pe[j-i];
    else if(bh==ch)for(int j=i;j<i+bl;j++)str[j]=ap[j-i];

    if(i+al<cl)ch=ch*B+c[i+al]-c[i]*t;
  }
}

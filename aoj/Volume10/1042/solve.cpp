#include<iostream>
#include<string>

using namespace std;

int main(void){
  string s;  

  while(1){
    getline(cin,s);
    if(s=="END OF INPUT")break;

    int len=s.size();
    for(int i=0,count=0;i<=len;i++){
      if(s[i]==' '||i==len){
	cout << count;
	count=0;
      }
      else count++;
    }
    cout << endl;
  }

  return 0;
}

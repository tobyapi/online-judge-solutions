#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>

#define all(c) (c).begin(),(c).end()

using namespace std;

int main(void){

  set<string>S;
  string str="AIDUNYAN";

  sort(all(str));

  do{
    S.insert(str);
  }while(next_permutation(all(str)));

  cin >> str;
  for(int i=0;i+7<str.size();i++){
    if(S.count(str.substr(i,8))){
      str=str.substr(0,i)+"AIZUNYAN"+str.substr(i+8,str.size()-8);
      i+=7;
    }
  }

  cout << str << endl;

  return 0;
}

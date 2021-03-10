#include <iostream>
#include <set>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;
 
int main(void){
  set<int> n;
  map<int,int> m;
  string in;

  while(getline(cin, in)){
    if(in.size()==0) break;
    m[atoi(in.c_str())]++;
  }

  while(getline(cin, in)){
    int num=atoi(in.c_str());
    if(m[num]>0){
      n.insert(num);
      m[num]++;
    }
  }

  for(set<int>::iterator it=n.begin(); it!=n.end(); it++)
    cout << *it << " " << m[*it] << endl;
   
  return 0;
}

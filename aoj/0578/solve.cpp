#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int N;
  string name, old_name[110];
  cin >> N;
  cin >> name;

  for(int i = 0 ; i < N ; i++){
    cin >> old_name[i];
  }
  
  int ans = 0;

  for(int i = 0 ; i < N ; i++){
    bool f = false;
    for(int j = 1 ; j <= old_name[i].size()/(name.size()-1) ; j++){ // Kankaku
      for(int k = 0 ; k < old_name[i].size() ; k++){ // Start
	string t = "";
	for(int l = k ; ; l += j){
	  if(t.size() == name.size() || old_name[i].size() < l) break;
	  t += old_name[i][l];
	}
	//cout << t << endl;
	if(t == name){
	  //cout << "find " << i << endl;
	  f = true;
	  ans++;
	}
	if(f) break;
      }
      if(f) break;
    }
  }
  
  cout << ans << endl;
}

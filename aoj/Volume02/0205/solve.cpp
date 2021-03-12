#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  int a;
  bool fg[4];
  vector<int>v;

  while(true){

    v.clear();
    fill(fg,fg+4,false);

    for(int i=0;i<5;i++){
      cin >> a;
      if(a==0)return 0;
      v.push_back(a);
    }    

    for(int i=0;i<5;i++)fg[v[i]]=true;
    if((fg[1] && fg[2] && fg[3]) ||
       (fg[1] && !fg[2] && !fg[3]) ||
       (!fg[1] && !fg[2] && fg[3]) ||
       (!fg[1] && fg[2] && !fg[3])){
      for(int i=0;i<5;i++)cout << 3 << endl;
    }
    
    if(fg[1] && fg[2] && !fg[3]){
      for(int i=0;i<5;i++){
	if(v[i]==1)cout << 1 << endl;
	else if(v[i]==2)cout << 2 << endl;
      }
    } 
    if(fg[1] && !fg[2] && fg[3]){
      for(int i=0;i<5;i++){
      	if(v[i]==1)cout << 2 << endl;
	else if(v[i]==3)cout << 1 << endl;
      }
    }
    if(!fg[1] && fg[2] && fg[3]){
      for(int i=0;i<5;i++){
	if(v[i]==2)cout << 1 << endl;
	else if(v[i]==3)cout << 2 << endl;
      }
    }
	  
  }

  return 0;
}

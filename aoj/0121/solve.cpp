#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

int dx[4]={1,-1,4,-4};
map<string,int>res;


void solve(void){
  queue<string>que;

  que.push("01234567");

  while(!que.empty()){

    string v=que.front();

    que.pop();

    int pos=0;
    for(int i=0;i<8;i++)
      if(v[i]=='0')pos=i;

    for(int i=0;i<4;i++){
      if(0 <= pos+dx[i] && pos+dx[i]<8 && 
	 !(pos==3 && i==0) && !(pos==4 && i==1)){
	string u=v;
	swap(u[pos],u[pos+dx[i]]);

	if(res[u]==0){
	  que.push(u);
	  res[u]=res[v]+1;
	}
      }
    }
  }

}

int main(void){
  int in;
  
  res["01234567"]=1;

  solve();

  while(true){
    string s;
    for(int i=0;i<8;i++){
      if(!(cin >> in))return 0;
      s+=in+'0';
    }

    cout << res[s]-1 << endl;
  }

  return 0;
}

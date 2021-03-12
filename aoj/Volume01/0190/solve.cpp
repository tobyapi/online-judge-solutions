#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

map<vector<int>,int>mp,used;

struct State{
  vector<int>v;
  int t;
  State(vector<int>v,int t):v(v),t(t){}
};

vector<vector<int> > generate(vector<int> v){
  vector<vector<int> >res;

  for(int i=0;i<13;i++){
    if(v[i]==0){
      vector<int>tmp=v;
      switch(i){
      case 0:
	swap(tmp[0],tmp[2]);
	res.push_back(tmp);
	break;
      case 1:
	swap(tmp[1],tmp[2]);
	res.push_back(tmp);
	swap(tmp[1],tmp[2]);
	swap(tmp[1],tmp[5]);
	res.push_back(tmp);
	break;
      case 2:
	swap(tmp[2],tmp[0]);
	res.push_back(tmp);
	swap(tmp[2],tmp[0]);

	swap(tmp[2],tmp[1]);
	res.push_back(tmp);
	swap(tmp[2],tmp[1]);

	swap(tmp[2],tmp[3]);
	res.push_back(tmp);
	swap(tmp[2],tmp[3]);

	swap(tmp[2],tmp[6]);
	res.push_back(tmp);
	break;
      case 3:
	swap(tmp[3],tmp[2]);
	res.push_back(tmp);
	swap(tmp[3],tmp[2]);

	swap(tmp[3],tmp[7]);
	res.push_back(tmp);
	break;
      case 4:
	swap(tmp[4],tmp[5]);
	res.push_back(tmp);
	break;
      case 5:
	swap(tmp[5],tmp[1]);
	res.push_back(tmp);
	swap(tmp[5],tmp[1]);

	swap(tmp[5],tmp[4]);
	res.push_back(tmp);
	swap(tmp[5],tmp[4]);

	swap(tmp[5],tmp[6]);
	res.push_back(tmp);
	swap(tmp[5],tmp[6]);

	swap(tmp[5],tmp[9]);
	res.push_back(tmp);
	break;
      case 6:
	swap(tmp[6],tmp[2]);
	res.push_back(tmp);
	swap(tmp[6],tmp[2]);

	swap(tmp[6],tmp[5]);
	res.push_back(tmp);
	swap(tmp[6],tmp[5]);

	swap(tmp[6],tmp[7]);
	res.push_back(tmp);
	swap(tmp[6],tmp[7]);

	swap(tmp[6],tmp[10]);
	res.push_back(tmp);
	break;
      case 7:
	swap(tmp[7],tmp[3]);
	res.push_back(tmp);
	swap(tmp[7],tmp[3]);

	swap(tmp[7],tmp[6]);
	res.push_back(tmp);
	swap(tmp[7],tmp[6]);

	swap(tmp[7],tmp[8]);
	res.push_back(tmp);
	swap(tmp[7],tmp[8]);

	swap(tmp[7],tmp[11]);
	res.push_back(tmp);
	break;
      case 8:
	swap(tmp[8],tmp[7]);
	res.push_back(tmp);
	break;
      case 9: 
	swap(tmp[9],tmp[5]);
	res.push_back(tmp);
	swap(tmp[9],tmp[5]);

	swap(tmp[9],tmp[10]);
	res.push_back(tmp);
	break;
      case 10:
	swap(tmp[10],tmp[6]);
	res.push_back(tmp);
	swap(tmp[10],tmp[6]);

	swap(tmp[10],tmp[9]);
	res.push_back(tmp);
	swap(tmp[10],tmp[9]);

	swap(tmp[10],tmp[11]);
	res.push_back(tmp);
	swap(tmp[10],tmp[11]);

	swap(tmp[10],tmp[12]);
	res.push_back(tmp);
	break;
      case 11:
	swap(tmp[11],tmp[7]);
	res.push_back(tmp);
	swap(tmp[11],tmp[7]);

	swap(tmp[11],tmp[10]);
	res.push_back(tmp);
	break;
      case 12:
	swap(tmp[12],tmp[10]);
	res.push_back(tmp);
	break;
      }
    }
  }
  return res;
}

void bfs(void){

  queue<State>que;
  vector<int>s;
  for(int i=0;i<12;i++)s.push_back(i);
  s.push_back(0);
  que.push(State(s,0));

  while(!que.empty()){
    State now=que.front();
    que.pop();
    
    if(mp.count(now.v) && now.t>=mp[now.v])continue;
    if(now.t>=12)continue;

    mp[now.v]=now.t;

    vector<vector<int> >res=generate(now.v);
    for(int i=0;i<res.size();i++){
      que.push(State(res[i],now.t+1));
    }
  }
}

int bfs(vector<int> s){
  
  used.clear();
  
  queue<State>que;
  que.push(State(s,0));
  
  while(!que.empty()){
    State now=que.front();
    que.pop();
    
    if(now.t>=11)continue;
    if(used.count(now.v))continue;
    if(mp.count(now.v))return now.t+mp[now.v];
    used[now.v]=1;
    
    vector<vector<int> >res=generate(now.v);
    for(int i=0;i<res.size();i++){
      que.push(State(res[i],now.t+1));
    }
  }
  return -1;
}

int main(void){

  bfs();

  while(true){
    vector<int>s(13);
    for(int i=0;i<13;i++){
      cin >> s[i];
      if(s[i]<0)return 0;
    }
    int res=bfs(s);
    if(res<0 || res>20)cout << "NA" << endl;
    else cout << res << endl;
  }

  return 0;
}

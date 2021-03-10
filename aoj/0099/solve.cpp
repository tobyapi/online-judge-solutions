#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int main(void){

  int n,q,cnt[1000001];
  priority_queue<P>que;
  que.push(P(0,-1));
  fill(cnt,cnt+1000001,0);

  cin >> n >> q;
  while(q--){
    int a,v;
    cin >> a >> v;
    cnt[a]+=v;
    que.push(P(cnt[a],-a));
    while(true){
      P res=que.top();
      if(res.first==cnt[-res.second]){
	cout << -res.second << " " << res.first << endl;
	break;
      }
      que.pop();
    }
  }
  return 0;
}

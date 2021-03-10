#include<iostream>
#include<queue>

using namespace std;

int n[1000001];

int func(int x){
  priority_queue<int>que;
  int ans;
  for(int i=2;i<=x;i++){
    if(n[i]==0 && x%i==0)que.push(i);
  }

  ans=que.top();
  que.pop();
  while(!que.empty()){
    ans-=que.top();
    que.pop();
  }
  return ans;
}

int main(void){
  int a,b;

  for(int i=0;i<1000001;i++)n[i]=0;
  n[0]=n[1]=1;

  for(int i=2;i*i<1000001;i++){
    if(n[i]==0){
      for(int j=2*i;j<1000001;j+=i){
	n[j]=1;
      }
    }
  }

  while(cin >> a >> b,a|b){
    int resa=func(a);
    int resb=func(b);
    if(resa>resb)cout << "a" << endl;
    else cout << "b" << endl;
  }

  return 0;
}

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

#define all(c) (c).begin(),(c).end()

using namespace std;

vector<int>p,v;
bool fg[101000];

int main(void){

  for(int i=2;i*i<101000;i++){
    if(!fg[i]){
      for(int j=i*i;j<101000;j+=i){
	fg[j]=true;
      }
    }
  }
  for(int i=2;i<101000;i++)
    if(!fg[i])p.push_back(i);

  int N,P;
  while(cin >> N >> P,0<=N && 0<=P){
    int b = upper_bound(all(p),N) - p.begin();
    int psize = p.size();
    v.clear();
    for(int i=b;i-b<P && i<psize;i++){
      for(int j=i;j-i<P && j<psize;j++){
	v.push_back(p[i]+p[j]);
      }
    }
    sort(all(v));
    cout << v[P-1] << endl;
  }
  
  return 0;
}

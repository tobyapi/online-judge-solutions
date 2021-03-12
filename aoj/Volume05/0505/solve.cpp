#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> P;

bool cmp(P x,P y){
  if(x.first!=y.first)return x.first>y.first;
  return x.second < y.second;
}

int main(void){

  int n,m,in,p[101];
  
  while(cin >> n >> m,n|m){
    
    fill(p,p+m+1,0);
    
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	cin >> in;
	p[j+1]+=in;
      }
    }

    vector<P>res;
    for(int i=1;i<=m;i++){
      res.push_back(make_pair(p[i],i));
    }

    sort(res.begin(),res.end(),cmp);

    for(int i=0;i<res.size();i++){
      cout << res[i].second;
      if(i<res.size()-1)cout <<" ";
      else cout << endl;
    }

  }
  
  return 0;
}

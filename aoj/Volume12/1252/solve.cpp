#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define INF (1<<29)
#define all(c) (c).begin(),(c).end()

using namespace std;

typedef pair<string,string> pss;

int dist(string s,string t) {
  int d[20][20];
  fill(d[0],d[20],INF);

  int n=s.size(),m=t.size();
  for(int i=0;i<=n;i++)d[i][0]=i;
  for(int i=0;i<=m;i++)d[0][i]=i;
  
  int sp[128],tp[128];
  fill(sp,sp+128,-1);
  for(int i=0;i<n;sp[s[i]]=i,i++){
    fill(tp,tp+128,-1);
    for(int j=0;j<m;tp[t[j]]=j,j++){
      int cost=(s[i]!=t[j]);
      int ii=sp[t[j]],jj=tp[s[i]];
      d[i+1][j+1]=min(min(d[i][j+1],d[i+1][j])+1,d[i][j]+cost);
      if(ii>=0 && jj>=0)
	d[i+1][j+1]=min(d[i+1][j+1],d[ii][jj]+i-ii+j-jj-1);
    }
  }
  return d[n][m]; 
}

int main(void){

  int n,d;
  while(cin >> n,n){
    cin >> d;
    vector<string> v(n);
    for(int i=0;i<n;i++)cin >> v[i];

    vector<pair<string,string> >res;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
	if(dist(v[i],v[j])<=d){
	  res.push_back(pss(min(v[i],v[j]),max(v[i],v[j])));
	}
      }
    }
    sort(all(res));
    for(int i=0;i<res.size();i++)
      cout << res[i].first << "," << res[i].second << endl;
    cout << res.size() << endl;
  }

  return 0;
}

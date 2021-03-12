#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define all(c) (c).begin(),(c).end()
#define f first
#define s second

using namespace std;

typedef long long ll;

struct point{ll x,y,z;};

typedef pair<point,point> P;

int main(void){
  ll n,k,x1,x2,y1,y2,z1,z2;
  vector<ll>x,y,z;

  cin >> n >> k;
  vector<P> p(n);

  for(int i=0;i<n;i++){
    cin >> p[i].f.x >> p[i].f.y >> p[i].f.z;
    cin >> p[i].s.x >> p[i].s.y >> p[i].s.z;

    x.push_back(p[i].f.x);
    x.push_back(p[i].s.x);
    y.push_back(p[i].f.y);
    y.push_back(p[i].s.y);
    z.push_back(p[i].f.z);
    z.push_back(p[i].s.z);
  }
  
  sort(all(x));
  sort(all(y));
  sort(all(z));

  map<ll,int>X,Y,Z;
  
  for(int i=0;i<x.size();i++)X[x[i]]=i;
  for(int i=0;i<y.size();i++)Y[y[i]]=i;
  for(int i=0;i<z.size();i++)Z[z[i]]=i;
  
  int grid[101][101][101];
  for(int i=0;i<101;i++)
    for(int j=0;j<101;j++)
      for(int l=0;l<101;l++)grid[i][j][l]=0;

  for(int i=0;i<n;i++)
    for(int xi=X[p[i].f.x];xi<X[p[i].s.x];xi++)
      for(int yi=Y[p[i].f.y];yi<Y[p[i].s.y];yi++)
	for(int zi=Z[p[i].f.z];zi<Z[p[i].s.z];zi++)
	  grid[xi][yi][zi]++;

  ll ans=0;
  for(int i=0;i<x.size()-1;i++)
    for(int j=0;j<y.size()-1;j++)
      for(int l=0;l<z.size()-1;l++)
	if(grid[i][j][l]>=k)
	  ans+=(x[i+1]-x[i])*(y[j+1]-y[j])*(z[l+1]-z[l]);
  
  cout << ans << endl;

  return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

#define all(c) (c).begin(),(c).end()
#define x second
#define y first
#define a first
#define b second
#define PUSH 0
#define SUM 1
#define POP 2

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int>piii;
typedef pair<pii,pii> segment;

const int MAX_N = 1<<17;
int n,dat[2*MAX_N];

void init(int n_){
  n=1;
  while(n<n_)n*=2;
  fill(dat,dat+2*MAX_N,0);
}

void update(int k,int a){
  k+=n-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=dat[k*2+1]+dat[k*2+2];
  }
}

int sum(int a,int b,int k=0,int l=0,int r=n){
  if(r<=a || b<=l)return 0;
  if(a<=l && r<=b)return dat[k];
  
  int m=(l+r)/2;
  int vl=sum(a,b,k*2+1,l,m);
  int vr=sum(a,b,k*2+2,m,r);
  return vl+vr;
}

map<int,int> xmp;

struct Q{
  int y,x1,x2,q;
  Q(){}
  Q(int y,int x1,int x2,int q):y(y),x1(x1),x2(x2),q(q){}
};

bool cmp(Q p,Q q){
  if(p.y!=q.y)return p.y<q.y;
  return p.q<q.q;
}

int main(void){

  int m;
  cin >> m;
  
  vector<int>xv;
  vector<segment>v(m);
  vector<Q>query;
  
  for(int i=0;i<m;i++){
    cin >> v[i].a.x >> v[i].a.y >> v[i].b.x >> v[i].b.y;

    if(v[i].a.x>v[i].b.x)swap(v[i].a.x,v[i].b.x);
    if(v[i].a.y>v[i].b.y)swap(v[i].a.y,v[i].b.y);

    xv.push_back(v[i].a.x);
    xv.push_back(v[i].b.x);
  }
  
  sort(all(xv));

  for(int i=0;i<m;i++){
    if(v[i].a.x==v[i].b.x){
      query.push_back(Q(v[i].a.y,v[i].a.x,-1,PUSH));
      query.push_back(Q(v[i].b.y,v[i].b.x,-1,POP));
    }
    if(v[i].a.y==v[i].b.y){
      query.push_back(Q(v[i].a.y,v[i].a.x,v[i].b.x,SUM));
    } 
  }
  
  sort(all(query),cmp);

  xv.erase(unique(all(xv)),xv.end());

  for(int i=0;i<xv.size();i++)xmp[xv[i]]=i;

  init(xv.size());
  
  int cnt=0;
  for(int i=0;i<query.size();i++){
    if(query[i].q==PUSH)update(xmp[query[i].x1],1);
    if(query[i].q==POP)update(xmp[query[i].x1],0);
    if(query[i].q==SUM)cnt+=sum(xmp[query[i].x1],xmp[query[i].x2]+1);
  }
  cout << cnt << endl;
  
  return 0;
}

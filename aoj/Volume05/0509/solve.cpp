#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#define F first
#define S second

using namespace std;

typedef pair<int,int> P;

bool cmp_x( const pair<P,P> &p , const pair<P,P> &q ){return p.F < q.F;}
bool cmp_y( const pair<P,P> &p , const pair<P,P> &q ){return p.S < q.S;}

int main(void){
  
  int n,r,x1,x2,y1,y2;
  
  while(cin >> n >> r){
    if(n==0 && r==0)break;
    
    vector<pair<P,P> > in;
    
    for(int i=0;i<n;i++){
      scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
      in.push_back(make_pair(make_pair(x1,x2), make_pair(y1,y2)));
    }
    
    sort(in.begin(),in.end(),cmp_x);
    
    int S=0,L=0;
    vector<P>v;
    for(int i=0;i+1<10001;i++){
      v.clear();
      for(int j=0;j<n;j++){
	if(in[j].S.S>=i+1 && i>=in[j].S.F)
	  v.push_back(make_pair(in[j].F.F,in[j].F.S));
      }
      
      if(v.size()!=0){
	int b=v[0].F,e=v[0].S;
	for(int j=1;j<v.size();j++){
	  int B=v[j].F,E=v[j].S;
	  if(e>=B)e=max(e,E);
	  else S+=e-b, b=B, e=E, L+=2;
	}
	S+=e-b, L+=2;
      }
    }
    cout << S << endl;
    
    if(r==2){  
      sort(in.begin(),in.end(),cmp_y);
      
      for(int i=0;i+1<10001;i++){
	v.clear();
	for(int j=0;j<n;j++){
	  if(in[j].F.S>=i+1 && i>=in[j].F.F)
	    v.push_back(make_pair(in[j].S.F,in[j].S.S));
	}
	if(v.size()!=0){
	  int b=v[0].F,e=v[0].S;
	  
	  for(int j=1;j<v.size();j++){
	    int B=v[j].F,E=v[j].S;
	    
	    if(e>=B)e=max(e,E);
	    else b=B, e=E, L+=2;
	  }
	  L+=2;
	}
      }
      cout << L << endl;
    }
  }
  return 0;
}

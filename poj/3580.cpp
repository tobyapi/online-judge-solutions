#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>

#define INF (1<<29)

using namespace std;

typedef long long ll;

template<class T>
struct RBST{
public:
  struct node_t{
    T val,mini,lazy;
    int size;
    node_t *lch,*rch;
    bool rev;
    
    node_t(int v):val(v),mini(v){
      size=1;
      lazy=0;
      lch=rch=0;
      rev=false;
    }
  };

  node_t *root;  
  RBST():root(0){srand(time(NULL));}

private:

  int val(node_t *t){return t->val+t->lazy;}
  int size(node_t *x){return !x?0:x->size;}
  int mini(node_t *t){return !t?INF:t->mini+t->lazy;}
  
  node_t *update(node_t *t){
    
    if(!t)return t;
    
    t->size=size(t->lch)+size(t->rch)+1;
    t->mini=min(min(mini(t->lch),mini(t->rch)),val(t));
    
    if(t->lazy){
      t->val+=t->lazy;
      if(t->lch)t->lch->lazy+=t->lazy;
      if(t->rch)t->rch->lazy+=t->lazy;
      t->lazy=0;
    }
    
    if(t->rev){
      swap(t->lch,t->rch);
      if(t->lch)t->lch->rev^=true;
      if(t->rch)t->rch->rev^=true;
      t->rev=false;
    }  
    return t;
  }
  
  node_t* merge(node_t *l,node_t *r){
    l=update(l),r=update(r);
    if(!l || !r)return l?l:r;
    
    int m=l->size,n=r->size;
    if(rand()%(m+n)<m){
      l->rch=merge(l->rch,r);
      return update(l);
    } else {
      r->lch=merge(l,r->lch);
      return update(r);
    }
  }
  
  typedef pair<node_t*,node_t*>pnn;
  
  pnn split(node_t *t,int k){
    if(!update(t))return pnn(0,0);
    if(k<=size(t->lch)){
      pnn tmp=split(t->lch,k);
      t->lch=tmp.second;
      return pnn(tmp.first,update(t));
    } else {
      pnn tmp=split(t->rch,k-size(t->lch)-1);
      t->rch=tmp.first;
      return pnn(update(t),tmp.second);
    }
  }
  
  node_t *insert(node_t *t,int k,int val){
    pair<node_t *,node_t *>s=split(t,k);
    t=merge(s.first, new node_t(val));
    t=merge(t,s.second);
    return update(t);
  }
  
  node_t *erase(node_t *t,int k){
    pair<node_t *,node_t *>s1,s2;
    s2=split(t,k+1);
    s1=split(s2.first,k);
    delete s1.second;
    return update((t=merge(s1.first,s2.second)));
  }
  
  node_t *find(node_t *t, int k){
    int c=size(t->lch);
    if(k<c)return find(t->lch, k);
    if(k==c)return t;
    return find(t->rch, k-c-1);
  }

public:
  
  void insert(int k,T val){ root=insert(root,k,val); }
  void erase(int k){ root=erase(root,k); }
  node_t *find(int k){ return find(root,k); }

  void add(int id,T val){
    node_t *a=find(id);
    T tmp=val(a);
    erase(id);
    insert(id,tmp+val);
  }

  void rangeAdd(int l,int r,T v){
    pair<node_t *,node_t *>s1,s2;
    s2=split(root,r);
    s1=split(s2.first,l);
    s1.second->lazy+=v;
    root=merge(s1.first,s1.second);
    root=merge(root,s2.second);
  }

  void update(int id,T val){
    erase(id);
    insert(id,val);
  }

  T rangeMinimumQuery(int l,int r){
    pair<node_t *,node_t *>s1,s2;
    s2=split(root,r);
    s1=split(s2.first,l);
    T res=mini(s1.second);
    root = merge(s1.first,merge(s1.second,s2.second));
    return res;
  }

  T rangeSumQuery(int l,int r){
    pair<node_t *,node_t *>s1,s2;
    s2=split(root,r);
    s1=split(s2.first,l);
    T res=sum(s1.second);
    root = merge(s1.first,merge(s1.second,s2.second));
    return res;
  }

  void reverse(int l,int r){
    pair<node_t *,node_t *>s1,s2;
    s2=split(root,r);
    s1=split(s2.first,l);
    node_t *a=s1.first,*b=s1.second,*c=s2.second;
    b->rev^=true;
    root=merge(a,b);
    root=merge(root,c);
  }

  void revolve(int l,int r,int t){
    t%=(r-l);
    pair<node_t*, node_t*>a,b,c;
    c=split(root, r);
    b=split(c.first, r-t);
    a=split(b.first, l);
    root=merge(a.first, b.second);
    root=merge(root, a.second);
    root=merge(root, c.second);
  }
};

//POJ 3580
int main(void){
  
  int n,m,in;
  RBST<ll> t;
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&in);
    t.insert(i,in);
  }
  
  cin >> m;
  
  char com[10];
  int x,y,T,D,P;

  for(int i=0;i<m;i++){
    scanf("%s",com);

    if(com[0]=='A'){
      scanf("%d %d %d",&x,&y,&D);
      t.rangeAdd(x-1,y,D);
    }
    else if(com[0]=='R' && com[3]=='E'){
      scanf("%d %d",&x,&y);
      t.reverse(x-1,y);
    }
    else if(com[0]=='R' && com[3]=='O'){
      scanf("%d %d %d",&x,&y,&T);
      t.revolve(x-1,y,T);
    }
    else if(com[0]=='I'){
      scanf("%d %d",&x,&P);
      t.insert(x,P);
    }
    else if(com[0]=='D'){
      scanf("%d",&x);
      t.erase(x-1);
    }
    else if(com[0]=='M'){
      scanf("%d %d",&x,&y);
      printf("%lld\n",t.rangeMinimumQuery(x-1,y));
    }
  }    
  return 0;
}
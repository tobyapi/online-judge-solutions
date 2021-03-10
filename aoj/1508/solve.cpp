#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

#define INF (1<<29)

using namespace std;

template<class T>
struct treap{
  struct node_t{
    T val;
    T sum;
    node_t *lch, *rch;
    int pri;
    int cnt;
    node_t(T v, int p):val(v),pri(p),cnt(1),sum(v){
      lch=rch=NULL;
    }
  };
  node_t *root;
  treap():root(NULL){}

  int count(node_t *t){return t?t->cnt:0; }
  T   sum(node_t *t){return t?t->sum:INF;}
  int size(){return count(root);}

  node_t *update(node_t *t){
    t->cnt=count(t->lch)+count(t->rch)+1;
    t->sum=min(min(sum(t->lch),sum(t->rch)),t->val);
    return t;
  }
  node_t *merge(node_t *l, node_t *r){
    if(!l||!r) return l?l:r;
    if(l->pri>r->pri){
      l->rch=merge(l->rch,r);
      return update(l);
    }
    else{
      r->lch=merge(l,r->lch);
      return update(r);
    }
  }
  pair<node_t*,node_t*> split(node_t *t,int k){
    if(!t) return make_pair((node_t*)NULL,(node_t*)NULL);
    if(k<=count(t->lch)){
      pair<node_t*,node_t*>s=split(t->lch,k);
      t->lch=s.second;
      return make_pair(s.first,update(t));
    }
    else{
      pair<node_t*,node_t*>s=split(t->rch,k-count(t->lch)-1);
      t->rch=s.first;
      return make_pair(update(t),s.second);
    }
  }
  node_t *insert(node_t *t,int k,T val,int pri){
    pair<node_t*, node_t*>s=split(t,k);
    t=merge(s.first, new node_t(val,pri));
    t=merge(t,s.second);
    return update(t);
  }
  node_t *erase(node_t *t,int k){
    pair<node_t*, node_t*>s1,s2;
    s2=split(t,k+1);
    s1=split(s2.first,k);
    t=merge(s1.first,s2.second);
    return update(t);
  }

  node_t *find(node_t *t,int k){
    int c=count(t->lch);
    if(k<c)return find(t->lch, k);
    if(k==c)return t;
    return find(t->rch,k-c-1);
  }

  void insert(int k,T val){root=insert(root,k,val,rand());}
  void erase(int k){root=erase(root,k);}
  node_t *find(int k){return find(root,k);}

  void shift(int l,int r){
    pair<node_t*,node_t*>a,b,c;
    c=split(root,r);
    b=split(c.first,r-1);
    a=split(b.first,l);
    root=merge(a.first,b.second);
    root=merge(root,a.second);
    root=merge(root,c.second);
  }

  int query(int l,int r,node_t *t){
    int sz=count(t);
    if(sz<=l || r<=0)return INF;
    if(l<=0 && sz<=r)return sum(t);

    int c=count(t->lch);
    int vl=query(l,r,t->lch);
    int vr=query(l-c-1,r-c-1,t->rch);
    int res=min(vl,vr);
    if(l<=c && c<r)res=min(res,t->val);
    return res;
  }
};

int main(void){

  srand(time(NULL));
  int n,q;
  treap<int> t;

  cin >> n >> q;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    t.insert(i,a);
  }

  for(int i=0;i<q;i++){
    int x,y,z;
    cin >> x >> y >> z;

    if(x==0)t.shift(y,z+1);
    else if(x==1)cout << t.query(y,z+1,t.root) << endl;
    else if(x==2){
      t.erase(y);
      t.insert(y,z);
    }
  }

  return 0;
}

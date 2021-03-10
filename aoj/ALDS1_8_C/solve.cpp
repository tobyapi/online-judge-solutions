#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
  int key;
  node *lp,*rp;

  node(){}
  node(int z):key(z),lp(NULL),rp(NULL){}

} *root;

void insert(node* z){
  node *x=root,*y=NULL;

  while(x){
    y = x;
    x = (z->key < x->key) ? x->lp : x->rp;
  }

  if(!y)root = z;
  else (z->key < y->key ? y->lp : y->rp) = z;
}

bool find(node *t, int v){
  if(!t)return false;
  if(t->key == v)return true;
  return find((v < t->key)?t->lp:t->rp,v);
}

void erase(node *t,int v,node *p){
  if(!t)return;
  if(t->key == v){
    if(!t->lp && !t->rp){
      (p->lp==t? p->lp : p->rp) = NULL;
      delete t;
    }
    else if(t->lp && t->rp){
      node *c = t->rp,*cp = t;
      while(c->lp)cp=c,c=c->lp;
      t->key = c->key;

      if(!c->lp && !c->rp){
        (cp->lp==c?cp->lp:cp->rp)=NULL;
        delete c;
      }
      else {
        node *cc = (c->lp) ? c->lp : c->rp;
        (cp->lp==c ? cp->lp : cp->rp) = cc;
        delete c;
      }
    }
    else {
      node *c = (t->lp) ? t->lp : t->rp;
      (p->lp==t? p->lp : p->rp) = c;
      delete t;
    }
    return;
  }
  return erase((v < t->key ? t->lp : t->rp),v,t);
}

vector<int> preorder, inorder;

void dfs(node *t = root){
  preorder.push_back(t->key);
  if(t->lp)dfs(t->lp);
  inorder.push_back(t->key);
  if(t->rp)dfs(t->rp);
}

int main(void) {

  root = NULL;

  int n,v;
  string s;
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> s;
    if(s=="insert"){
      cin >> v;
      insert(new node(v));
    } else if(s=="find"){
      cin >> v;
      cout << (find(root,v)?"yes":"no") << endl;
    } else if(s=="delete"){
      cin >> v;
      erase(root,v,root);
    } else {
      dfs();
      for(int j=0;j<inorder.size();j++)cout << " " << inorder[j];
      cout << endl;
      for(int j=0;j<preorder.size();j++)cout << " " << preorder[j];
      cout << endl;

      preorder.clear();
      inorder.clear();
    }
  }

  return 0;
}

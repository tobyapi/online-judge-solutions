#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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

vector<int> preorder, inorder;

int dfs(node *t = root){
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

  for(int i=0,m=0;i<n;i++){
    cin >> s;
    if(s=="insert"){
      cin >> v;
      insert(new node(v));
      m++;
    } else {
      dfs();
      for(int j=0;j<m;j++)cout << " " << inorder[j];
      cout << endl;
      for(int j=0;j<m;j++)cout << " " << preorder[j];
      cout << endl;

      preorder.clear();
      inorder.clear();
    }
  }

  return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> P;

mat mul(mat &A,mat &B){
  mat C(A.size(),vec(B[0].size()));
  for(int i=0;i<A.size();i++)
    for(int k=0;k<B.size();k++)
      for(int j=0;j<B[0].size();j++)
	C[i][j]+=A[i][k]*B[k][j];

  return C;
} 

mat pow(mat A,int n){
  mat B(A.size(),vec(A.size()));
  for(int i=0;i<A.size();i++)B[i][i]=1;
  for(;n>0;n>>=1){
    if(n&1)B=mul(B,A);
    A=mul(A,A);
  }
  return B;
}

int main(void){
  int n,m,z,s,d;

  while(cin >> n >> m >> z,n|m|z){
    vector<P>G;
    G.push_back(P(1,1));
    for(int i=0;i<m;i++){
      cin >> s >> d;
      G.push_back(P(s,d));
      G.push_back(P(d,s));
    }
    mat A(G.size(),vec(G.size()));
 
    for(int i=0;i<G.size();i++)
      for(int j=1;j<G.size();j++)
	if(i!=j && G[i].first!=G[j].second)
	  A[i][j]=G[i].second==G[j].first;

    A=pow(A,z);

    bool fg=false;
    for(int i=0;i<A.size();i++)
      if(G[i].second==n && A[0][i])fg=true;

    cout << (fg?"yes":"no") << endl;
  }
}

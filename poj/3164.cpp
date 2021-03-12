#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define pdi pair<double,int>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int N=110,M=1000000,INF=0x3f3f3f3f,MOD=1999997;
const double DNF=100000000000;

struct Node{
  double x,y;
}nod[N];
struct Edge{
  int u,v;
  double w;
}e[N*N];
int pre[N],id[N],vis[N];
double minw[N];
int n,m;

inline double dist(Node &a,Node &b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double zhu_liu(int root)
{
  int i,cou,u,v,k;
  double ans=0;
  while(1){
      mem(pre,-1);
      for(i=1;i<=n;i++)minw[i]=DNF;
      for(i=0;i<m;i++){
        u=e[i].u;
        v=e[i].v;
        if(e[i].w<minw[v] && u!=v){
          pre[v]=u;
          minw[v]=e[i].w;
        }
      }
      pre[root]=-1;minw[root]=0;
      for(cou=0,i=1;i<=n;i++){
        if(pre[i]==-1 && i!=root)cou++;
        else ans+=minw[i];
      }
      if(cou)return -1;
      mem(vis,0);
      mem(id,0);
      for(i=1,k=0;i<=n;i++){
        if(id[i])continue;
        u=i;
        while(u!=-1 && !id[u] && vis[u]!=i){
          vis[u]=i;
          u=pre[u];
        }
        if(u!=-1 && !id[u] && vis[u]==i){
          k++;
          while(id[u]!=k){
            id[u]=k;
            u=pre[u];
          }
        }
      }

      if(!k)break;
      for(i=1;i<=n;i++)if(!id[i])id[i]=++k;
      for(i=0;i<m;i++){
        e[i].w-=minw[e[i].v];
        e[i].u=id[e[i].u];
        e[i].v=id[e[i].v];
      }
      n=k;
      root=id[root];
    }
  return ans;
}

int main()
{
  int i,j,a,b;
  double c,ans;
  while(scanf("%d%d",&n,&m)!=EOF)
    {
      for(i=1;i<=n;i++)
        scanf("%lf%lf",&nod[i].x,&nod[i].y);
      for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        c=dist(nod[a],nod[b]);
        e[i].u=a,e[i].v=b,e[i].w=c;
      }

      ans=zhu_liu(1);
      if(ans>=0)printf("%.2f\n",ans);
      else printf("poor snoopy\n");
    }
  return 0;
}
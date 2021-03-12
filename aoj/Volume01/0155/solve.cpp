#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define INF 100000

using namespace std;

void dijkstra(int);
vector<int>get_path(int);

int V,prev[1001];
double cost[1001][1001],d[1001];
bool used[1001];

int main(void){

  int b[1001],m,s,g;
  double x[1001],y[1001];

  while(cin >> V,V){
    for(int i=0;i<V;i++)
      cin >> b[i] >> x[i] >> y[i];
    
    for(int i=0;i<=V;i++)
      for(int j=0;j<=V;j++)
	cost[i][j]=INF;

    for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
	if(i!=j){
	  double a=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
	  if(50.>=a)cost[b[i]][b[j]]=cost[b[j]][b[i]]=a;
	}
      }
    }
    
    cin >> m;
    for(int i=0;i<m;i++){
      cin>> s >> g;
      
	dijkstra(s);

	if(used[g]){

	  vector<int>p=get_path(g);

	  for(int j=0;j<p.size();j++){
	    cout << p[j];

	    if(j<p.size()-1)cout <<" ";
	    else cout << endl;
	  }
	}
	else cout << "NA" << endl; 
    }
  }
  
  return 0;
}

void dijkstra(int s){
  fill(d,d+V+1,INF);
  fill(used,used+V+1,false);
  fill(prev,prev+V+1,-1);
  d[s]=0;

  while(true){
    int v=-1;
    for(int u=1;u<=V;u++){
      if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
    }

    if(v==-1 || d[v]==INF)break;
    used[v]=true;

    for(int u=1;u<=V;u++){
      if(d[u]>d[v]+cost[v][u]){
	d[u]=d[v]+cost[v][u];
	prev[u]=v;
      }
    }
  }
}

vector<int>get_path(int t){
  vector<int>path;
  for(;t!=-1;t=prev[t])path.push_back(t);
  reverse(path.begin(),path.end());
  return path;
}

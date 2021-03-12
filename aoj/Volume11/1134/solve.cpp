#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
 
#define all(a) (a).begin(),(a).end()
#define pb(a) push_back((a))
#define mp(a,b) make_pair((a),(b))
#define fst first
#define sec second
 
using namespace std;
 
void split(string in,string& s1,string& s2){
  for(int i=0;i<in.size();i++){
    if(in[i]=='-'){
      s1=in.substr(0,i);
      s2=in.substr(i+1,in.size()-i-1);
      return;
    }
  }
}
 
multimap<string,string>m1,m2;
map<string,int>color;
 
void dfs(string v,int c){
  color[v]=c;
  multimap<string,string>::iterator it=m2.begin();
  while(it!=m2.end()){
    if((*it).fst==v && color[(*it).sec]==0)dfs((*it).sec,-c);
    it++;
  }
}
 
int graph[200][200];
 
void warshall_floyd(int V){
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++)
    graph[i][j]|=graph[i][k]&graph[k][j];
}
 
int main(void){
  int n,m;
  string in,s1,s2;
  vector<string>node,node3;
  map<string,int>node2;
  vector<pair<string,string> >query;
  
  while(cin >> n,n){
    m1.clear();
    m2.clear();
    color.clear();
    node.clear();
    node2.clear();
    node3.clear();
    query.clear();
    
    for(int i=0;i<n;i++){
      cin >> in;
      split(in,s1,s2);
      node.pb(s1);
      node.pb(s2);
      node3.pb(s1);
      node3.pb(s2);
      m1.insert(mp(s1,s2));
      m2.insert(mp(s1,s2));
      m2.insert(mp(s2,s1));
    }
    sort(all(node));
    node.erase(unique(all(node)),node.end());
    
    cout << node.size() << endl;

    cin >> m;
    for(int i=0;i<m;i++){
      cin >> in;
      split(in,s1,s2);
      query.pb(mp(s1,s2));
      node3.pb(s1);
      node3.pb(s2);
    }
    
    sort(all(node3));
    node3.erase(unique(all(node3)),node3.end());
    
    for(int i=0;i<node3.size();i++){
      color[node3[i]]=0;
      node2[node3[i]]=i;
    }
    
    for(int i=0,j=1;i<node3.size();i++)
      if(color[node3[i]]==0)dfs(node3[i],j++);
    
    bool g[200][200];
    for(int i=0;i<200;i++){
      for(int j=0;j<200;j++){
	g[i][j]=false;
	graph[i][j]=i==j?1:0; 
      }
    }
    
    multimap<string,string>::iterator it,it2;
    
    for(it=m1.begin();it!=m1.end();it++){
      for(it2=m1.begin();it2!=m1.end();it2++){
	if(it==it2)continue;
	
	if((*it).fst==(*it2).sec){
	  g[node2[(*it).sec]][node2[(*it2).fst]]=true;
	  g[node2[(*it2).fst]][node2[(*it).sec]]=true;
	}
	if((*it).sec==(*it2).fst){
	  g[node2[(*it).fst]][node2[(*it2).sec]]=true;
	  g[node2[(*it2).sec]][node2[(*it).fst]]=true;
	}
      }
    }
    

    for(it=m1.begin();it!=m1.end();it++){
      graph[node2[(*it).fst]][node2[(*it).sec]]=1;
      
   
      for(it2=m1.begin();it2!=m1.end();it2++){
	if(it==it2)continue;
	
	if((*it).fst==(*it2).fst && !g[node2[(*it).sec]][node2[(*it2).sec]]){
	  graph[node2[(*it).sec]][node2[(*it2).sec]]=1;
	  graph[node2[(*it2).sec]][node2[(*it).sec]]=1;
	}
	
	if((*it).sec==(*it2).sec && !g[node2[(*it).fst]][node2[(*it2).fst]]){
	  graph[node2[(*it).fst]][node2[(*it2).fst]]=1;
	  graph[node2[(*it2).fst]][node2[(*it).fst]]=1;
	}
      }
    }
    
    warshall_floyd(node3.size());
    
    for(int i=0;i<query.size();i++){
      if(color[query[i].fst]+color[query[i].sec]==0 &&
	 graph[node2[query[i].fst]][node2[query[i].sec]]==1)
	cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}

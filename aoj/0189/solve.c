#define INF 1000000
#define rep(i,n) for((i)=0;(i)<=(int)(n);(i)++)
void warshall_floyd(void);
int min(int,int);

int graph[10][10],n;

int main(void){
  int a,b,c,i,j,sum[10],ans1,ans2;

  while(scanf("%d",&n),n){

    rep(i,9)sum[i]=0;
    ans1=INF;

    rep(i,9){
      rep(j,9){
	graph[i][j]=INF;
      }
      graph[i][i]=0;
    }
    
    rep(i,n-1){
      scanf("%d %d %d",&a,&b,&c);
      graph[a][b]=graph[b][a]=c;
    }
    warshall_floyd();

    rep(i,9)
      rep(j,9)
	if(graph[i][j]<INF)sum[i]+=graph[i][j];

    rep(i,9){
      if(ans1>sum[i] && sum[i]>0){
	ans1=sum[i];
	ans2=i;
      }
    }
    printf("%d %d\n",ans2,ans1);
  }
  return 0;
}

void warshall_floyd(void){
  int i,j,k;

  rep(k,9)
    rep(i,9)
      rep(j,9)
	graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
}

int min(int x,int y){
  return x<y?x:y;
}

#include<iostream>
#include<vector>
#include<algorithm>
#define f first
#define s second
#define INF (1<<29)
using namespace std;

typedef pair<int,int> P;

int h,w,s,u[34][34];
P memo[34][34][34][34];

P rec(int x1,int y1,int x2,int y2){
	
	if(memo[x1][y1][x2][y2]!=P(0,INF))return memo[x1][y1][x2][y2];
	
	if(u[h-1][w-1]-(u[y2-1][x2-1]-u[y2-1][x1-1]-u[y1-1][x2-1]+u[y1-1][x1-1])>s)return P(0,INF);
	
	P res=P(1,s-(u[h-1][w-1]-(u[y2-1][x2-1]-u[y2-1][x1-1]-u[y1-1][x2-1]+u[y1-1][x1-1])));
	
	for(int i=x1+1;i<x2;i++){
		P a=rec(x1,y1,i,y2);
		P b=rec(i,y1,x2,y2);
		res=max(res,P(a.f+b.f,min(a.s,b.s)));
	}
	
	for(int i=y1+1;i<y2;i++){
		P a=rec(x1,y1,x2,i);
		P b=rec(x1,i,x2,y2);
		res=max(res,P(a.f+b.f,min(a.s,b.s)));
	}
	
	return memo[x1][y1][x2][y2]=res;
}

int main(void){
	
	while(cin >> h >> w >> s,h|w|s){
		
		for(int i=0;i<34;i++)
			for(int j=0;j<34;j++)
				for(int k=0;k<34;k++)
					for(int l=0;l<34;l++)
						memo[i][j][k][l]=P(0,INF);
		
		fill(u[0],u[33],0);
		h++,w++;
		
		for(int i=1;i<h;i++){
			for(int j=1;j<w;j++){
				cin >> u[i][j];
			}
		}
		
		for(int i=1;i<h;i++){
			for(int j=1;j<w;j++){
				u[i][j]+=u[i-1][j]+u[i][j-1]-u[i-1][j-1];
			}
		}
		
		P ans=rec(1,1,w,h);
		cout << ans.f << " " << ans.s << endl;
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#define x first.first
#define y first.second
#define r second.first
#define color second.second

using namespace std;

typedef pair<double,double> P;
typedef pair<P,P> C;

bool check(C a,C b){
  return a.r+b.r>sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
 
int count(int bits){
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits =(((bits >> 4) + bits) & 0x0f0f0f0f);
  bits += bits >> 8;
  return (bits + (bits >> 16)) & 0xff;
}
 
bool dp[(1<<25)];
 
int main(void){
 
	int n;
	while(cin >> n,n){
		C c[25];
		for(int i=0;i<n;i++){
			//cin >> c[i].x >> c[i].y >> c[i].r >> c[i].color;
			scanf("%lf %lf %lf %lf",&c[i].x,&c[i].y,&c[i].r,&c[i].color);
		}
		
		fill(dp,dp+(1<<n),false);
		dp[(1<<n)-1]=true;
		int ans=0;
		
		for(int S=(1<<n)-1;S>=0;S--){
			if(!dp[S])continue;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					
					int nx=S;
					nx&=~(1<<i);
					nx&=~(1<<j);
					if(dp[nx])continue;
					
					if(!(S>>i&1) || !(S>>j&1))continue;
					if(c[i].color!=c[j].color)continue;
					
					for(int k=0;k<n;k++){
						if(!(S>>k&1))continue;
						if((k<i && check(c[i],c[k]))||(k<j && check(c[j],c[k])))goto end;
					}
					
					dp[nx]|=dp[S];
					end:;
				}
			}
			if(dp[S])ans=max(ans,n-count(S));
		}
		cout << ans << endl;
	}
   
  return 0;
}

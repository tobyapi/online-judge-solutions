#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<cstdio>
      
#define f first
#define s second
      
using namespace std;
      
typedef pair<int,int> P;
      
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
      
int main(void){
      
int n,id=0;
string idx="ABCDEFGHI";
char s,t,d;
map<char,P>mp;
      
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
mp[idx[id++]]=P(j,i);
}
}
      
while(cin >> n,n){
cin >> s >> t >> d;
   
P S=mp[s],T=mp[t],D=mp[d];
   
double dp[16][3][3];
      
for(int k=0;k<16;k++)
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)dp[k][i][j]=0;
      
dp[0][S.s][S.f]=1;
      
for(int k=0;k<n;k++){
for(int y=0;y<3;y++){
for(int x=0;x<3;x++){
for(int l=0;l<4;l++){
int nx=x+dx[l],ny=y+dy[l];
if(nx<0 || ny<0 || 2<nx || 2<ny || 
(nx==D.f&&ny==D.s))nx=x,ny=y;
dp[k+1][ny][nx]+=dp[k][y][x]/4;
}
}
}
}
printf("%.8f",dp[n][T.s][T.f]);
cout << endl;
}
      
return 0;
}

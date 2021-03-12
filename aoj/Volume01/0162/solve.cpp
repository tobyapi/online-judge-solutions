#include <iostream>
using namespace std;

int ans;

void dfs(int i){
if(i==1){ans++; return;}
if(i%2==0)dfs(i/2);
else if(i%3==0)dfs(i/3);
else if(i%5==0)dfs(i/5);
return;
}

int main(){
int m, n;
while(cin>>m, m){
cin>>n;
ans=0;

for(int i=m; i<=n; i++)dfs(i);
cout<<ans<<"\n";
}
return 0;
}

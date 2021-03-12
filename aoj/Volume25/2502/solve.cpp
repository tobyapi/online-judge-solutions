#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
int n,m,s[400],l[400],p[400],w[400],dp[400];

cin >> n;
for(int i=0;i<n;i++)
cin >> s[i] >> l[i] >> p[i];

cin >> m;
for(int i=0;i<m;i++)cin >> w[i];

fill(dp,dp+400,-1);
dp[0]=0;

for(int i=1;i<400;i++){
for(int j=0;j<n;j++){
for(int k=s[j];k<=l[j];k++){
if(i-k>=0)dp[i]=max(dp[i],dp[i-k]+p[j]);
}
}
}

for(int i=0;i<m;i++){
if(dp[w[i]]<0){
cout << -1 << endl;
return 0;
}
}


for(int i=0;i<m;i++){
cout << dp[w[i]] << endl;
}

return 0;
}

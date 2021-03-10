#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main(void){
 
int n,m,ans;
 
while(cin >> n >> m){
ans=0;
for(int i=0;i<n;i++){
int sum=0;
for(int j=0;j<m;j++){
int in;
cin >> in;
sum+=in;
}
ans=max(ans,sum);
}
cout << ans << endl;
}
 
return 0;
}

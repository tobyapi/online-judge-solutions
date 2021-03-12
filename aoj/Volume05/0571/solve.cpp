#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define all(c) (c).begin(),(c).end()

using namespace std;

int main(void){

  string s;
  cin >> s;
  int n=s.size();
  vector<int>J(n),O(n),I(n);

  fill(all(J),0);
  fill(all(O),0);
  fill(all(I),0);
  
  if(s[0]=='J')J[0]=1;
  if(s[0]=='O')O[0]=1;
  if(s[0]=='I')I[0]=1;

  for(int i=1;i<n;i++){
    if(s[i]=='J')J[i]=J[i-1]+1;
    if(s[i]=='O')O[i]=O[i-1]+1;
    if(s[i]=='I')I[i]=I[i-1]+1;
  }
  
  int ans=0;
  for(int i=0;i<n;i++){
    if(i-I[i]-O[i-I[i]]<0)continue;
    if(I[i]>=O[i-I[i]] && O[i-I[i]]<=J[i-I[i]-O[i-I[i]]])
      ans=max(ans,min(I[i],min(J[i-I[i]-O[i-I[i]]],O[i-I[i]])));
  }

  cout << ans << endl;
  
  return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef pair<string,int> P;

int main(void){

  int n,t;

  cin >> n >> t;

  char ch;
  vector<string>a(n),b(n);
  vector<int>ha(n),hb(n),ma(n),mb(n);
  for(int i=0;i<n;i++){
    cin >> ha[i] >> ch >> ma[i] >> a[i];
    cin >> hb[i] >> ch >> mb[i] >> b[i];
  }

  vector<P>ans;
  for(int i=0;i<n-1;i++){
    int time=(ha[i+1]*60+ma[i+1])-(hb[i]*60+mb[i]);
    if(time>=t)ans.push_back(P(b[i],time));
  }

  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++)
    cout << ans[i].first << " " << ans[i].second << endl;

  return 0;
}

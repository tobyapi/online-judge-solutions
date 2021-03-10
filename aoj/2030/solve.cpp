#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int func(vector<int> num){
  int ans=0;
  for(int i=0;i<num.size()-1;i++)
    ans+=(num[i+1]-num[i])*(num[i+1]-num[i]);
  return ans;
}


int main(void){

  int a,b,tmp;
  vector<int>num;

  while(cin >> a >> b,a|b){
    int res=INT_MAX;
    for(int i=1;i*i<=a;i++)
      for(int j=1;j*j<=b;j++)
	if(a%i==0 && b%j==0){
	  num.clear();
	  num.push_back(a/i);
	  num.push_back(i);
	  num.push_back(b/j);
	  num.push_back(j);
	  sort(num.begin(),num.end());
	  res=min(res,func(num));
	}

    cout << res << endl;
  }

  return 0;
}

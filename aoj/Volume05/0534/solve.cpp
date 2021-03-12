#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Erase(vector<int> a){
  for(int i=0,j=0;j<a.size();){
    if(a[j]==a[j+1])j++;
    else {
      if(j-i>2){
	a.erase(a.begin()+i,a.begin()+j+1);
	i=j=0;
      }
      else j++,i=j;
    }
  }
  return a.size();
}

int main(void){
  int n,m;
  vector<int>a;

  while(cin >> n,n){
    a.clear();
    for(int i=0;i<n;i++){
      cin >> m;
      a.push_back(m);
    }

    int ans=100000000;
    for(int i=0;i<a.size();i++){
      int temp=a[i];
      for(int j=1;j<4;j++){
	if(temp!=j){
	  a[i]=j;
	  ans=min(ans,Erase(a));
	}
      }
      a[i]=temp;
    }
    cout << ans << endl;
  }

  return 0;
}

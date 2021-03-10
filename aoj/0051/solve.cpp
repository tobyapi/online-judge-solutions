#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
  vector<int>num;
  char ch[10];
  int n,maxn,minn;

  cin >> n;
  cin.ignore();
  while(n--){
    scanf("%[^\n]%*c",ch);

 for(int i=0;i<8;i++)num.push_back(ch[i]-'0');
      
    sort(num.begin(),num.end(),greater<int>());
 
    maxn=0;
    for(int i=0;i<8;i++)
      maxn*=10,maxn+=num[i];

    sort(num.begin(),num.end());

    minn=0;
    for(int i=0;i<8;i++)
      minn*=10,minn+=num[i];

    cout << maxn-minn << endl;
    num.clear();
  }

  return 0;
}

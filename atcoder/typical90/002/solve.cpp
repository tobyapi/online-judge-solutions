#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define all(c) (c).begin(),(c).end()

using namespace std;

vector<string>result;

int dfs(int index, int size, string cur){
  if(size <= cur.size()){
    result.push_back(cur);
    return index;
  }
  for(int i=index;i<cur.size();i++){
    string next = cur.substr(0, i) + "()" + cur.substr(i, cur.size() - i);
    index = dfs(i, size, next);
  }
  return index;
}

int main(void){
  int N;
  cin >> N;
  if(N%2 == 1)return 0;
  dfs(0, N, "()");
  sort(all(result));
  result.erase(unique(all(result)), result.end());
  for(int i=0;i<result.size();i++)
    cout << result[i] << endl;
  return 0;
}
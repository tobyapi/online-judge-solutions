#include<iostream>
#include<vector>

using namespace std;

int n;

vector<int> cut(int k,vector<int> cards){
  vector<int>res;
  for(int i=k;i<2*n;i++)res.push_back(cards[i]);
  for(int i=0;i<k;i++)res.push_back(cards[i]);
  return res;
}

vector<int> riffle(vector<int> cards){
  vector<int>res;
  for(int i=0;i<n;i++){
    res.push_back(cards[i]);
    res.push_back(cards[n+i]);
  }
  return res;
}

int main(void){
  int m,k;
  vector<int> cards;

  cin >> n >> m;
  for(int i=1;i<=2*n;i++)cards.push_back(i);
  for(int i=0;i<m;i++){
    cin >> k;
    cards = k ? cut(k,cards) : riffle(cards);
  }
  for(int i=0;i<2*n;i++)cout << cards[i] << endl;

  return 0;
}

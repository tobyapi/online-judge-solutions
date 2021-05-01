#include<iostream>
#include<vector>
#include<algorithm>

#define all(c) (c).begin(),(c).end()

using namespace std;

bool check(vector<int>A, int score, int K){
  int prev = 0;
  for(int i=0;i<A.size();i++){
    if(score <= A[i] - prev && 0 < K){
      prev = A[i];
      K--;
    }
  }
  return score <= A[A.size() - 1] - prev && K == 0;
}

int binary_search(vector<int>A, int K){
  int l=0, r=(1<<29);
  while(r-l>1){
    int mid = (l+r)/2;
    (check(A, mid, K) ? l : r) = mid;
  }
  return l;
}

int main(void) {
  int N, L, K;
  cin >> N >> L >> K;

  vector<int>A(N);
  for(int i=0;i<N;i++)cin >> A[i];
  A.push_back(L);

  cout << binary_search(A, K) << endl;
  return 0;
}
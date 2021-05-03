#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#define all(c) (c).begin(),(c).end()

using namespace std;

int search(const vector<int> &A, int B) {
  int l = 0, r = A.size()-1;
  while(r-l > 1){
    int mid = (l + r) / 2;
    (A[mid] < B ? l : r) = mid;
  }
  return min(max(B, A[l]) - min(B, A[l]), max(B, A[r]) - min(B,A[r]));
}

int main(void){
  int N, Q;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++)cin >> A[i];

  sort(all(A));

  cin >> Q;
  while(Q--){
    int B;
    cin >> B;
    cout << search(A, B) << endl;
  }
  return 0;
}
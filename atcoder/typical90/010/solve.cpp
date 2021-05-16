#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll sum[2][100001];

int main(void){
  int N;
  cin >> N;

  for(int i=0;i<N;i++){
    int C, P;
    cin >> C >> P;
    sum[C-1][i] += P;
    sum[0][i + 1] += sum[0][i];
    sum[1][i + 1] += sum[1][i];
  }

  int Q;
  cin >> Q;
  while(Q--){
    int L, R;
    cin >> L >> R;
    L--, R--;
    if(0 < L)cout << sum[0][R] - sum[0][L-1] << " " << sum[1][R] - sum[1][L-1] << endl;
    else cout << sum[0][R] << " " << sum[1][R] << endl;
  }
  return 0;
}
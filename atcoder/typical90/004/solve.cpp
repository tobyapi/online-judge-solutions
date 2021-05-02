#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#define all(c) (c).begin(),(c).end()

using namespace std;

vector<vector<int> > A;

int main(void){
  int H, W;
  cin >> H >> W;

  A.resize(H, vector<int>(W));
  vector<int> col(H), row(W);

  fill(all(row), 0);
  fill(all(col), 0);

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      scanf("%d", &A[i][j]);
      col[i] += A[i][j];
      row[j] += A[i][j];
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << col[i] + row[j] - A[i][j] << (j + 1 < W ? " " : "\n");
    }
  }
  return 0;
}
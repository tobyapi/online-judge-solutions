#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char grid[8][8];

void rotate(){

  char tmp[8][8];
  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      tmp[i][j]=grid[7-j][i];

  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      grid[i][j]=tmp[i][j];
}

void print(){

  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      cout << grid[i][j];
    }
    cout << endl;
  }
}

int main(void){

  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      cin >> grid[i][j];

  cout << 90 << endl;
  rotate();
  print();

  cout << 180 << endl;
  rotate();
  print();

  cout << 270 << endl;
  rotate();
  print();

  return 0;
}

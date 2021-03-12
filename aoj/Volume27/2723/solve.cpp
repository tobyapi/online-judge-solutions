#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

struct Cube {
  int x,y,z;
  
  Cube(){}
  Cube(int x,int y,int z):x(x),y(y),z(z){}

  bool operator == (Cube that){
    return x == that.x && y == that.y && z == that.z;
  }
};

bool is_adjecent(Cube a, Cube b){
  for(int i=-1;i<=1;i++){
    if(a == Cube(b.x+i, b.y, b.z))return true;
    if(a == Cube(b.x, b.y+i, b.z))return true;
    if(a == Cube(b.x, b.y, b.z+i))return true;
  }
  return false;
}

int count_exposure(Cube cube,int a,int b,int c){
  return
  (cube.x == 0) + (cube.x == a-1) +
  (cube.y == 0) + (cube.y == b-1) +
  (cube.z == 0) + (cube.z == c-1);
}
  
int main(void){

  ll a,b,c,n;

  cin >> a >> b >> c >> n;

  vector<Cube>cubes(n);
  
  for(int i=0;i<n;i++)
    cin >> cubes[i].x >> cubes[i].y >> cubes[i].z;
  
  ll cnt=2*(a*b+b*c+c*a)+6*n;
  for(int i=0;i<n;i++){
    cnt -= 2*count_exposure(cubes[i],a,b,c);
    for(int j=i+1;j<n;j++){
      cnt -= 2*is_adjecent(cubes[i], cubes[j]);
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}

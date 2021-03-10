#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

struct cube{
  int x,y,z;
};

bool operator<(const cube& left, const cube& right){
  if(left.x != right.x)return left.x < right.x ;
  if(left.y != right.y)return left.y < right.y ;
  return left.z < right.z ;
}


int main(void){
  set<cube>st;
  string c;
  int n,h,a,b;

  while(cin >> n >> h,n|h){
    st.clear();
    
    for(int i=0;i<h;i++){
      cin >> c >> a >> b;

      cube in;
    
      if(c=="xy"){
	in.x=a;
	in.y=b;
	for(int j=1;j<=n;j++){
	  in.z=j;
	  st.insert(in);
	}
      }
      else if(c=="xz"){
	in.x=a;
	in.z=b;
	for(int j=1;j<=n;j++){
	  in.y=j;
	  st.insert(in);
	}	
      }
      else if(c=="yz"){
	in.y=a;
	in.z=b;
	for(int j=1;j<=n;j++){
	  in.x=j;
	  st.insert(in);
	}
      }
    }
      cout << n*n*n-st.size() << endl;
  }

  return 0;
}

#include<iostream>
#include<cmath>
#define INF 1000000000

using namespace std;

int main(void){

  int n;
  double i,h,w,ans,bmi;

  while(cin >> n,n){
    ans=INF,bmi=INF;

    for(int j=0;j<n;j++){
      cin >> i >> h >> w;
      if(abs(22-bmi)>abs(22-w/(h*h/10000))||
	 (abs(22-bmi)==abs(22-w/(h*h)/10000) && i<ans)){
	ans=i,bmi=w/(h*h/10000);
      }
    }
    cout << ans << endl;
  }

  return 0;
}

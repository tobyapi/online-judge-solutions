#include<iostream>
          
using namespace std;

int main(void){
  
  int w,a[3]={125,140,160};
  
  while(cin >> w,~w){
    int res=1150;
    w-=10;      
    
    for(int i=0;i<3 && 0<w;i++){
      if(9<w  && i<2)w-=10,res+=10*a[i];
      else{
	res+=w*a[i];
	break;
      }
    }
 
    cout << 4280-res << endl;
  }
  
  return 0;
}

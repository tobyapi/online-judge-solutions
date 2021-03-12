#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
  int n,sum,a[26],b[26],total;

  while(1){
    total=0;
    fill(a,a+26,0);
    fill(b,b+26,0);
    
    cin >> n ;
    if(n==0)break;
    
    for(int i=0;i<n;i++){
      cin >> a[i] >> b[i] ;
      total+=a[i];
    }
    
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
	if(b[i]>b[j]){
	  int t=b[i];
	  b[i]=b[j];
	  b[j]=t;
	  t=a[i];
	  a[i]=a[j];
	  a[j]=t;
	}
      }
    }
   
    sum=0;

    for(int i=0;i<n;i++){
      if(sum+a[i]<=b[i])sum+=a[i];
      else break;
    } 
    printf((sum==total)?"Yes\n":"No\n");
  }
  return 0;
}

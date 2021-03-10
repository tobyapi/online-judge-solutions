#include<iostream>
using namespace std;

int main(void){
  long long sosu[50001],i,j,n;

  sosu[0]=1;
  sosu[1]=1;

  for(i=2;i<50001;i++)
    sosu[i]=0;

  for(i=2;i<50001;i++){
    if(sosu[i]==0){
      for(j=i*i;j<50001;j+=i)
	sosu[j]=1;
    }
  }

  while(1){
    int count=0;
    cin >> n;
    if(n==0)break;    

    for(i=0;i<n/2+1;i++){
      if(sosu[i]==0 && sosu[n-i]==0)count++;
}

    /*   for(i=0;i<n;i++){
      for(j=0;j<n/2+1;j++){
	if(sosu[i]==0&&sosu[j]==0&&n==i+j)count++;
      }
      }*/
    cout << count << endl;
  }
  return 0;
}

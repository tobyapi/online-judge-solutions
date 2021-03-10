#include<iostream>

using namespace std;

int main(void){
  long long x,emp[4001],val[4001];
  long long emp1,val1,con,flag;

  while(1){
    cin >> x;
    if(x==0)break;

    for(int i=0;i<4001;i++){
      emp[i]=0;
      val[i]=0;
    }
    for(int i=0;i<x;i++){
      cin >> emp1 >> val1 >> con;

      flag=0;
      for(int j=0;j<x;j++){
	if(emp[j]==emp1){
	  flag=1;
	  val[j]+=val1*con;
	  break;
	}
      }
      if(flag==0){
	for(int j=0;j<4001;j++){
	  if(emp[j]==0){
	    emp[j]=emp1;
	    val[j]=val1*con;
	    break;
	  }  
	}
      }
    }
      flag=0;
    for(int j=0;j<4001;j++){
      if(val[j]>=1000000){
	cout << emp[j] << endl;
	flag=1;
      }
    }
    if(flag==0)cout << "NA" << endl;
  }
  return 0;
}

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int max(int,int);

int main(void){
  char str[200];
  int a,b;
  
  while(1){
    for(int i=0;i<200;i++){
      str[i]='\0';
    }
    scanf("%[^\n]%*c",str);
    a=0;
    b=0;
    if(str[0]=='0')break;
    
    for(int i=1;str[i]!='\0';i++){  
      if(str[i]=='A')a++;
      else if(str[i]=='B')b++;
    }
    
    if(a==max(a,b))a++;
    else if(b==max(a,b))b++;
    cout << a <<" "<< b << endl;
  }
  
  return 0;
}

int max(int x,int y){
  return (x<y)?y:x;
}

#include<stdio.h>

int main(void){
int n,x,stack[11],i;
while(scanf("%d",&n),n){

for(i=0;n>0;i++){
x=n%8;
stack[i]=(x==4)?5:(x<4)?x:x+2;
n=n/8;
}
for(;i>0;i--)printf("%d",stack[i-1]);
printf("\n");
}
return 0;
} 

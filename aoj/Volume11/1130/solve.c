#include<stdio.h>

void visit(int i,int j);

int v[21][21],count,H,W;
char s[21][21];

int main(void){
  int i,j;
  
  while(1){

    for(i=0;i<21;i++){
      for(j=0;j<21;j++)
	s[i][j]='#';
}
    for(i=0;i<21;i++){
      for(j=0;j<21;j++)
	v[i][j]=0;
    }
    count=0;
    scanf("%d %d",&W,&H);
    if(W==0 && H==0)break;

    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
	scanf(" %c",&s[i][j]);
      }
    }

    for(i=0;i<H;i++){
      for(j=0;j<W;j++){
	if(s[i][j]=='@'){
	  visit(i,j);
	}
      }
    }
    printf("%d\n",count);
  }
  return 0;
}

void visit(int i,int j){
  v[i][j]=1;
  count++;
  if(s[i+1][j]=='.' && i<H && v[i+1][j]==0)visit(i+1,j);
  if(s[i-1][j]=='.' && i!=0 && v[i-1][j]==0)visit(i-1,j);
  if(s[i][j+1]=='.' && j<W && v[i][j+1]==0)visit(i,j+1);
  if(s[i][j-1]=='.' && j!=0 && v[i][j-1]==0)visit(i,j-1);
}

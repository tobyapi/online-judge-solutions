int North(void);
int East(void);
int West(void);
int South(void);
int Right(void);
int Left(void);

int top,front,r,l,back,bottom;

int main(void){
  int n,sum,i;
  char s[7];
  
  while(1){
    scanf("%d",&n);
    if(n==0)break;

    top=1;
    front=2;
    r=3;
    l=4;
    back=5;
    bottom=6;

    sum=top;

    for(i=0;i<n;i++){
      scanf(" %s",s);

      if(strcmp(s,"North")==0)sum+=North();
      else if(strcmp(s,"East")==0)sum+=East();
      else if(strcmp(s,"South")==0)sum+=South();
      else if(strcmp(s,"West")==0)sum+=West();
      else if(strcmp(s,"Left")==0)sum+=Left();
      else if(strcmp(s,"Right")==0)sum+=Right();
    }
    printf("%d\n",sum);
  }
  return 0;
}

int North(void){
  int t;

  t=top;
  top=front;
  front=bottom;
  bottom=back;
  back=t;

  return top;
}

int East(void){
  int t;

  t=top;
  top=l;
  l=bottom;
  bottom=r;
  r=t;

  return top;
}

int West(void){
  int t;

  t=top;
  top=r;
  r=bottom;
  bottom=l;
  l=t;

  return top;
}

int South(void){
  int t;

  t=top;
  top=back;
  back=bottom;
  bottom=front;
  front=t;

  return top;
}

int Right(void){
  int t;

  t=front;
  front=r;
  r=back;
  back=l;
  l=t;

  return top;
}

int Left(void){
  int t;

  t=front;
  front=l;
  l=back;
  back=r;
  r=t;

  return top;
}

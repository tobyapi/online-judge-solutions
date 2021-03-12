int st[31],i,s;
int main(void){
  for(;~scanf("%d",&s);)st[s]++;
  for(i=1;i<31;i++)st[i]!=0?:printf("%d\n",i);
  return 0;
}

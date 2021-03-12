main(a,b){
  for(gets(b);~scanf("%d%d",&a,&b);)
    printf("%d\n",a=sqrt(b-a)*2-1e-9);
}
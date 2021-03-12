main(D,V){
  for(;scanf("%d%d",&D,&V),D;)
    printf("%.3f\n",cbrt(D*D*D-V/asin(.5)));
}
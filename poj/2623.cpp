c(int *a,int *b){return *a-*b;}
d['abc'],n,i,m;
main(){
  scanf("%d",&n);
  for(;i<n;++i)scanf("%d",d+i);
  qsort(d,n,4,c);
  m=n/2;
  printf("%.1f",n%2?d[m]:d[m]/2.+d[m-1]/2.);
}
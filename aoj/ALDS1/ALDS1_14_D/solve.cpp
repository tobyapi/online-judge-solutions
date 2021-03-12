#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>

#define REP(i, n) for (int i=0;i<int(n);++i)
#define REPV(i, v, n) for (int i=0,tmp=v;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)

using namespace std;

typedef unsigned char byte;

byte mask[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
#define tget(i) !!(t[(i)>>3]&mask[(i)&7])
#define tset(i, b) t[(i)>>3]=(b) ? (mask[(i)&7]|t[(i)>>3]) : ((~mask[(i)&7])&t[(i)>>3])
#define chr(i) (cs==sizeof(int)?((int*)s)[i]:((byte *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))

void getBuckets(byte *s, int *bkt, int n, int K, int cs, bool end=true){
  fill(bkt, bkt + K + 1, 0);
  REP(i,n)bkt[chr(i)]++;
  REPV(i, 0, K+1)tmp += bkt[i], bkt[i] = end ? tmp : tmp - bkt[i];
}

void induceSAl(byte *t, int *SA, byte *s, int *bkt, int n, int K, int cs, bool end=false){
  getBuckets(s, bkt, n, K, cs, end);
  REP(i,n)if(SA[i]>0 && !tget(SA[i]-1)) SA[ bkt[chr(SA[i]-1)]++ ] = SA[i]-1;
}

void induceSAs(byte *t, int *SA, byte *s, int *bkt, int n, int K, int cs, bool end=true){
  getBuckets(s, bkt, n, K, cs, end);
  DWN(i,n,0)if(SA[i]>0 && tget(SA[i]-1))SA[--bkt[chr(SA[i]-1)]] = SA[i]-1;
}

void SA_IS(byte *s, int *SA, int n, int K=128, int cs=1) {
  byte t[(n >> 3) + 1];
  int bkt[K + 1],n1=0,name=0;
  
  tset(n-2, 0), tset(n-1, 1);
  DWN(i,n-2,0)tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1))));
  getBuckets(s, bkt, n, K, cs);
  fill(SA, SA+n, -1);
  FOR(i,1,n)if(isLMS(i))SA[--bkt[chr(i)]] = i;

  induceSAl(t, SA, s, bkt, n, K, cs);
  induceSAs(t, SA, s, bkt, n, K, cs);
  
  REP(i,n)if(isLMS(SA[i]))SA[n1++] = SA[i];
  fill(SA + n1, SA + n, -1);

  REPV(i,-1,n1){
    int pos = SA[i], diff = false;
    for(int d = 0; d < n && !diff; d++){
      diff = chr(pos+d) != chr(tmp+d) || tget(pos+d) != tget(tmp+d);
      if(!diff && d && (isLMS(pos+d) || isLMS(tmp+d)))break;
    }
    if(diff)name++,tmp=pos;
    SA[ n1 + ((pos - (pos & 1)) >> 1) ] = name - 1;
  }
  int *s1 = SA + n - n1;
  for(int i=n-1,j=n-1;i>=n1;i--)if(SA[i]>=0)SA[j--]=SA[i];
  if(name < n1)SA_IS((byte*)s1, SA, n1, name - 1, sizeof(int));
  else REP(i,n1)SA[s1[i]]=i;
  
  getBuckets(s, bkt, n, K, cs);
  for(int i = 1, j = 0; i < n; i++)if(isLMS(i))s1[j++] = i;
  REP(i,n1)SA[i]=s1[SA[i]];
  fill(SA + n1, SA + n, -1);

  DWN(i,n1,0){
    int tmp = SA[i];
    SA[i] = -1, SA[--bkt[chr(tmp)]] = tmp;
  }
  induceSAl(t, SA, s, bkt, n, K, cs);
  induceSAs(t, SA, s, bkt, n, K, cs);
}

const int maxn = 1000001;
int n,sa[maxn];

bool contain(string S, int *sa, string T){
  int a = 0, b = S.length();
  while( b - a > 1 ){
    int c = (a + b ) / 2;
    if ( S.compare(sa[c], T.length(), T) < 0 ) a = c;
    else b = c;
  }
  return S.compare(sa[b], T.length(), T) == 0;
}

char a[maxn],b[maxn];

int main(void){
  int q;
  scanf("%s", a);
  string s = string(a);
  SA_IS((byte*) s.c_str(), sa, s.size()+1);

  scanf("%d", &q);
  while(q--){
    scanf("%s", b);
    if(contain(s, sa, string(b))) printf("1\n");
    else printf("0\n");
  }

  return 0;
}

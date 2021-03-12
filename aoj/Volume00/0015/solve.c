#include<stdio.h>
#include<string.h>
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define N 10

void mpAdd(int *,int *,int *);
void mpNum2Str(char *,int *);
void mpStr2Num(int *,char *);

int main(void){
  int ans[1000],a[1000],b[1000],i,j,n;
  char ach[1000],bch[1000],str[1000];

  scanf("%d",&n);
  
  rep(j,n){
    scanf("%s",ach);
    scanf("%s",bch);    
    mpStr2Num(a,ach);
    mpStr2Num(b,bch);
    mpAdd(ans,a,b);
    mpNum2Str(str,ans);
    
    if(strlen(str)>80)printf("overflow\n");
    else printf("%s\n",str);
  }
  return 0;
}

void mpAdd(int *ret, int *a, int *b){
    int  i;
    int  lr, la, lb;
    int  *rr;
    int  x;

    la = *a;
    lb = *b;
    lr = (la >= lb) ? la : lb;

    rr = ret;
    x = 0;
    for (i = 1; i <= lr; i++) {
        if (i <= la) x += *++a;
        if (i <= lb) x += *++b;
        if (x < N) {
            *++rr = x;
            x = 0;
        } else {
            *++rr = x - N;
            x = 1;
        }
    }
    *++rr = x;
    *ret = lr + x;
}

void mpNum2Str(char *str, int *num){
    int  i, j;
    char *ss;
    int  x;

    if (*num == 0) {
        *str++ = '0';
        *str = '\0';
        return;
    }

    ss = str - 1;
    for (i = *num; i > 0; i--) {
        x = *++num;
        for (j = 1; j < N; j *= 10) {
            *++ss = x % 10 + '0';
            x /= 10;
        }
    }
    while (*ss == '0') ss--;

    *(ss + 1) = '\0';    
    while (str < ss) {
        x = *str;
        *str++ = *ss;
        *ss-- = x;
    }
}

void mpStr2Num(int *num, char *str){
    char *ss;
    int  *nn;
    int  k;
    int  x;

    while (*str == ' ' || *str == '\t') str++;
    while (*str == '0') str++;
    ss = str;
    while (*ss >= '0' && *ss <= '9') ss++;

    if (ss == str) {
        *num = 0;
        return;
    }

    x = 0;
    k = 1;
    nn = num;
    do {
        x += (*--ss - '0') * k;
        k *= 10;
        if (k == N || ss == str) {
            *++nn = x;
            x = 0;
            k = 1;
        }
    } while (ss != str);

    *num = nn - num;
}

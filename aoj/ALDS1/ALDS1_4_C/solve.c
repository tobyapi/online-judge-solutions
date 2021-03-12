#include<stdio.h>
#include<string.h>

#define M 1000007
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
}

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){ return key%M; }
int h2(int key){ return (1+key)%(M-1); }

int find(char str[]){
  long long trip; 
  int i = 0;
  long long sum = getKey(str);
 
  while(1){
    trip = (h1(sum)+ i * h2(sum)) % M;
    if(strcmp(H[trip], str) == 0) return 1;
    if(H[trip][0] == '\0') return 0;
    i++;
  }
  return 0;
}

int insert(char str[]){
  int i = 0;
  long long ago;
  long long sum = getKey(str);
  
  while(1){
    ago = (h1(sum)+ i * h2(sum)) % M;
    if(H[ago][0] == '\0' || strcmp(H[ago],str) == 0){
      strcpy(H[ago], str);
      break;
    }
    i++;
  }
}

int main(){
  int i, n, h;
    char str[L], com[9];
    for ( i = 0; i < M; i++ ) H[i][0] = '\0';
    
    scanf("%d", &n);
    
    for ( i = 0; i < n; i++ ){
      scanf("%s %s", com, str);
      
      if ( com[0] == 'i' ){
	insert(str);
      } else {
	if (find(str)){
	  printf("yes\n");
	} else {
	  printf("no\n");
	}
      }
    }
    
    return 0;
}

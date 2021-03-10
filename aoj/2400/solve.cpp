#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(void){
   
   string s;
   int T,P,R,tID,pID,time,cor[51][501],wr[51][501],pena[51][501],corcnt[51];   

   while(cin >> T >> P >> R,T|P|R){

      memset(cor,0,sizeof(cor));
      memset(wr,0,sizeof(wr));
      memset(pena,0,sizeof(pena));
      memset(corcnt,0,sizeof(corcnt));
      
      for(int i=0;i<R;i++){
	 cin >> tID >> pID >> time >> s;
	 if(s=="CORRECT"){
	    corcnt[tID]++;
	    cor[tID][pID]++;
	    pena[tID][pID]+=wr[tID][pID]*1200+time;
	 }
	 else wr[tID][pID]++;
      }

      int pena2[51];
      memset(pena2,0,sizeof(pena2));
      for(int i=1;i<=T;i++){
	 for(int j=1;j<=P;j++){
	    pena2[i]+=pena[i][j];
	 }
      }

      int m,n,a;

      for(int i=1;i<=T;i++){
	 m=0;
	 for(int j=1;j<=T;j++){
	    m=max(corcnt[j],m);
	 }
	 n=1000000000;
	 for(int j=1;j<=T;j++){
	    if(corcnt[j]==m && pena2[j]<n){
	       a=j;
	       n=pena2[j];
	    }
	 }
	 cout << a <<" "<< corcnt[a] <<" "<< pena2[a] << endl;
	 corcnt[a]=-1;
      }
   }
   return 0;
}

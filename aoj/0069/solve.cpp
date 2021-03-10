#include<iostream>
#include<algorithm>

using namespace std;

int d,a[31][12];

bool ok(int s,int g){
	for(int i=0;i<d;i++){
		if(a[i][s-1]==1)s--;
		else if(a[i][s]==1)s++;
	}
	if(s==g)return true;
	return false;
}

int main(void){

	int n,m,g;
	char in;
	
	while(cin >> n,n){
		
		fill(a[0],a[31],0);

		cin >> m >> g >> d;
		
		for(int i=0;i<d;i++){
			for(int j=1;j<n;j++){
				cin >>in;
				a[i][j]=in-'0';
			}
		}

		if(ok(m,g)){
			cout << 0 << endl;
			continue;
		}
		
		bool fg=false;
		int p,q;
		
		for(int i=0;i<d;i++){
			for(int j=1;j<n;j++){
				if(a[i][j]==0 && a[i][j-1]==0 && a[i][j+1]==0){
					a[i][j]=1;
					fg=ok(m,g);
					if(fg){
						p=i+1,q=j;
						break;	
					}
					a[i][j]=0;
				}
			}
			if(fg)break;
		}
		if(fg)cout << p << " " << q << endl;
		else cout << 1 << endl;
		
	}
	
return 0;
}

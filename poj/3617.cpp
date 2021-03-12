#include<string>
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main(void){
	
	int n;
	char ch[2001];
	
	cin >> n;
	
	for(int i=0;i<n;i++)cin >> ch[i];
	
	int a=0,b=n-1,cnt=0;
	
	while(a<=b){
		cnt++;
		bool left=false;
		for(int i=0;a+i<=b;i++){
			if(ch[a+i]<ch[b-i]){
				left=true;
				break;
			}
			else if(ch[a+i]>ch[b-i]){
				left=false;
				break;
			}
		}
		if(left)cout << ch[a++];
		else cout << ch[b--];
		if(cnt%80==0)cout << endl;
	}
	cout << endl;
	
  return 0;
}
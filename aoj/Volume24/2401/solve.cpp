#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int now,al;
string s;

bool formula(void){
	
	if(isupper(s[now])){
		now++;
		return s[now-1]=='T';
	}
	
	if(islower(s[now])){
		now++;
		return (al>>(s[now-1]-'a'))&1;
	}
	
	if(s[now]=='('){
		now++;
		bool res1=formula();
		
		if(s[now]=='*'){
			now++;
			bool res2=formula();
			if(s[now]==')')now++;
			return res1&res2;
		}
		if(s[now]=='+'){
			now++;
			bool res2=formula();
			if(s[now]==')')now++;
			return res1|res2;
		}
		if(s[now]=='-' && s[now+1]=='>'){
			now+=2;
			bool res2=formula();
			if(s[now]==')')now++;
			if(res1==true && res2==false)return false;
			return true;
		}
	}
	
	if(s[now]=='-'){
		now++;
		bool res=formula();
		return !res;
	}
}

bool equation(void){
	bool res1=formula();
	now++;
	bool res2=formula();
	return (res1==res2);
}

int main(void){
	
	while(cin >> s,s!="#"){
		bool fg=true;
		for(al=0;al<(1<<11);al++)now=0,fg&=equation();
		if(fg)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

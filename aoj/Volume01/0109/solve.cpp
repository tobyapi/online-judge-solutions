#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int expression();
int term();
int factor();
int number();

int now;
string s;

int expression(){
	int res=term();
		while(true){
		if(s[now]=='+')now++,res+=term();
		else if(s[now]=='-')now++,res-=term();
		else break;
	}
	return res;
}

int term(){
	int res=factor();
	while(true){
		if(s[now]=='(')res+=factor();
		else if(s[now]=='*')now++,res*=factor();
		else if(s[now]=='/')now++,res/=factor();
		else break;
	}
	return res;
}

int factor(){
	int res=0;
	if(s[now]=='('){
		now++;
		res=expression();
		now++;
	}
	else return number();
	
	return res;
}

int number(){
	int res=0;
	while('0'<=s[now] && s[now]<='9'){
		res*=10;
		res+=s[now++]-'0';
	}
	return res;
}


int main(void){
	int n;
	cin >> n;
	
	while(n--){
		cin >> s;
		now=0;
		cout << expression() << endl;
	}
	
	return 0;
}

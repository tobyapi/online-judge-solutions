#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<map>

using namespace std;

int now;
string str;
map<string,int>mp;

int Number(void){
	string res;
	while('0'<=str[now] && str[now]<='9')res+=str[now++];
	return atoi(res.c_str());
}

int Atom(void){
	string s;
	s+=str[now++];
	if(islower(str[now]))s+=str[now++];
	if(mp.count(s))return mp[s];
	return -1;
}

int Molecule(void){
	
	int res=0;
	if(isupper(str[now])){
		res+=Atom();
		if(res<0)return -1;
		if('0'<=str[now] && str[now]<='9')res*=Number();
	}
	else if(str[now]=='('){
		now++;
		int tmp=Molecule();
		if(tmp<0)return -1;
		res+=tmp;
		now++;
		res*=Number();
	}
	
	if(now<str.size() && str[now]!=')'){
		int tmp=Molecule();
		if(tmp<0)return -1;
		res+=tmp;
	}
	return res;
}

int main(void){
	
	int n;
	string s;
	
	while(true){
		cin >> s;
		if(s=="END_OF_FIRST_PART")break;
		cin >> n;
		mp[s]=n;
	}
	
	while(true){
		cin >> str;
		if(str=="0")break;
		now=0;
		int res=Molecule();
		if(res<0)cout << "UNKNOWN" << endl;
		else cout << res << endl;
	}
	
return 0;
}

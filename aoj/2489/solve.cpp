#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#define all(c) (c).begin(),(c).end()

using namespace std;

string toStr(int n){
  stringstream ss;
  ss << n;
  return ss.str();
}

int main(void){
	
	vector<int>pnum;
	
	for(int i=0;i<20001;i++){
		string s=toStr(i);
		string r=s;
		reverse(all(r));
		if(s==r)pnum.push_back(i);
	}
	
	int n;
	while(cin >> n){
		vector<int>::iterator l;
		l=lower_bound(all(pnum),n);
	
		if(abs(n-*(l-1))>abs(n-*l))cout << *l << endl;
		else cout << *(l-1) << endl;
	}
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#define all(c) (c).begin(),(c).end()
#define f first
#define s second
#define INF (1<<29)

using namespace std;

typedef pair<int,int>pii;
typedef pair<pii,pii> P;

string s;
int h,w;
char g[51][51],tmp[51][51];
map<char,P>v;

void make(string s){
	fill(tmp[0],tmp[51],'.');
	for(int i=0;i<s.size();i++){
		for(int j=v[s[i]].f.s;j<=v[s[i]].s.s;j++){
			for(int k=v[s[i]].f.f;k<=v[s[i]].s.f;k++){
				tmp[j][k]=s[i];
			}
		}
	}
}

bool ok(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(g[i][j]!=tmp[i][j])return false;
		}
	}
	return true;
}

int main(void){

	int tc;
	cin >> tc;

	while(tc--){
		cin >> h >> w;
		for(int i=0;i<h;i++)cin >> g[i];

		s.clear();
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(g[i][j]!='.')s+=g[i][j];

		sort(all(s));
		s.erase(unique(all(s)),s.end());
		v.clear();
		for(int i=0;i<s.size();i++){
			int xmn=INF,ymn=INF,xmx=-1,ymx=-1;
			for(int j=0;j<h;j++){
				for(int k=0;k<w;k++){
					if(g[j][k]==s[i]){
						xmn=min(xmn,k);
						ymn=min(ymn,j);
						xmx=max(xmx,k);
						ymx=max(ymx,j);
					}
				}
			}
			v[s[i]]=P(pii(xmn,ymn),pii(xmx,ymx));
		}

		bool fg=false;
		do{
			make(s);
			if(ok()){fg=true;break;}
		}while(next_permutation(all(s)));

		if(fg)cout << "SAFE" << endl;
		else cout << "SUSPICIOUS" << endl;
	}

	return 0;
}

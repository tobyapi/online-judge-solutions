#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;

char G[501][501];
int g[501][501];

int main(void){

	int h,w;
	while(cin >> h >> w,h|w){
		fill(g[0],g[501],0);
		for(int i=0;i<h;i++)cin >> G[i];

		for(int i=0;i<w;i++)g[0][i]=(G[0][i]=='.');
		for(int i=1;i<h;i++){
			for(int j=0;j<w;j++){
				if(G[i][j]=='.')g[i][j]=g[i-1][j]+1;
			}
		}

		int ans=0;
		for(int i=0;i<h;i++){
			stack<pii> st;
			for(int j=0;j<w;j++){
				if(st.empty() || st.top().first<g[i][j])st.push(pii(g[i][j],j));
				else if(st.top().first>g[i][j]){
					int pos;
					while(!st.empty() && st.top().first>=g[i][j]){
						pos=st.top().second;
						ans=max(ans,(j-st.top().second)*st.top().first);
						st.pop();
					}
					st.push(pii(g[i][j],pos));
				}
			}
			
			while(!st.empty()){
				ans=max(ans,(w-st.top().second)*st.top().first);
				st.pop();
			}
			
		}
		cout << ans << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define h first
#define p second.first
#define q second.second
#define all(c) (c).begin(),(c).end()

using namespace std;

typedef pair<int,int>pii;
typedef pair<int,pii>piii;

int main(void){

	int n,m,a;

	while(cin >> n >> m >> a,n|m|a){
		vector<piii>v(m);
		for(int i=0;i<m;i++)cin >> v[i].h >> v[i].p >> v[i].q;
		sort(all(v));
		reverse(all(v));

		for(int i=0;i<m;i++){
			if(v[i].p==a)a=v[i].q;
			else if(v[i].q==a)a=v[i].p;
		}

		cout << a << endl;
	}

	return 0;
}

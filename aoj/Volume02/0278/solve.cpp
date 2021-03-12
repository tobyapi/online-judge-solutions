#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void){

	int n;
	cin >> n;

	while(n--){
		int x,y,b,p;
		cin >> x >> y >> b >> p;

		double t=x*b+y*p,u=(x*max(5,b)+y*max(2,p))*0.2,v=x*max(5,b)+y*max(2,p);
		cout << (int)min(t,v-u) <<endl;
	}

	return 0;
}

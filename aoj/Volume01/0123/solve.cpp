#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void){

	double a,b;
	while(cin >> a >> b){
		if(a<35.50 && b<71.0)cout << "AAA" << endl;
		else if(a<37.50 && b<77.0)cout << "AA" << endl;
		else if(a<40.0 && b<83.0)cout << "A" << endl;
		else if(a<43.0 && b<89.0)cout << "B" << endl;
		else if(a<50.0 && b<105.0)cout << "C" << endl;
		else if(a<55.0 && b<116.0)cout << "D" << endl;
		else if(a<70.0 && b<148.0)cout << "E" << endl;
		else cout << "NA" << endl;
	}

	return 0;
}

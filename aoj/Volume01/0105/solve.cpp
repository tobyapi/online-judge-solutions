#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

int main(void){

	string index;
	int page;
	map<string,set<int> >dic;
	
	while(cin >> index >> page)
		dic[index].insert(page);
	
	 map<string,set<int> >::iterator it = dic.begin();
    for(;it != dic.end();it++){
        cout << it->first << endl;
    	
        set<int>::iterator its = (it->second).begin();
    	
        while(its != (it->second).end()){
            cout << *its;
        	if(++its != (it->second).end())cout << " ";
        	else cout << endl;
        }
    }
	
return 0;
}

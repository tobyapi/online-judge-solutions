#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

int n,x,a[10];

while(cin >> n,n){
fill(a,a+10,0);

for(int i=0;i<n;i++){
cin >> x;
a[x]++;
}

for(int i=0;i<10;i++){
if(a[i]==0)cout <<"-"<<endl;
else {
for(int j=0;j<a[i];j++)cout <<"*";
cout << endl;
}
}
}

return 0;
}

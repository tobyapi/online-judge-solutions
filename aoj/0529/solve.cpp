#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int Bsearch(int);

vector<int>num2;

int main(void){
int n,m,t;
vector<int>num;

while(cin >> n >> m,n|m){
num.clear();
num2.clear();

for(int i=0;i<n;i++){
cin >> t;
num.push_back(t);
}

num.push_back(0);

for(int i=0;i<num.size();i++){
for(int j=0;j<num.size();j++){
num2.push_back(num[i]+num[j]);
}
}
sort(num2.begin(),num2.end());
vector<int>::iterator it = unique(num2.begin(),num2.end());
num2.erase(it, num2.end() );

int ans=0,c=num2.size(),tmp;
for(int i=0;i<c;i++){
tmp=Bsearch(m-num2[i]);
if(tmp+num2[i]>ans && tmp+num2[i]<=m)ans=tmp+num2[i];
}
cout << ans << endl;
}

return 0;
}

int Bsearch(int x){
int l=0,r=num2.size(),mid;

while(r-l>1){
mid=(l+r)/2;
if(num2[mid]>x)r=mid;
else if(num2[mid]==x)return num2[mid];
else if(num2[mid]<x)l=mid;
}
if(num2[mid]>x)return num2[mid-1];
return num2[mid];
}

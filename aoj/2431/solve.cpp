#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

const int MAX_N=1000000;

typedef long long ll;

using namespace std;

ll n,dat[2*MAX_N-1];

void init(int n_){
	n=1;
	while(n<n_)n*=2;
}

void update(int k,ll a){
	k+=n-1;
	dat[k]=a;
	
	while(k>0){
		k=(k-1)/2;
		dat[k]=max(dat[2*k+1],dat[2*k+2]);
	}
}

ll query(int a,int b,int k,int l,int r){
	if(r<=a || b<=l)return 0;
	if(a<=l && r<=b)return dat[k];
	else {
		ll vl=query(a,b,k*2+1,l,(l+r)/2);
		ll vr=query(a,b,k*2+2,(l+r)/2,r);
		return max(vl,vr);
	}
}

int main(void){
	
	ll in,m,ans=0;
	
	cin >> m;
	
	init(m);
	
	for(int i=0;i<m;i++){
		cin >> in;
		update(in,in+query(1,in,0,0,n));
	}
	cout << m*(m+1)/2-query(1,m+1,0,0,n) << endl;
	
	return 0;
}

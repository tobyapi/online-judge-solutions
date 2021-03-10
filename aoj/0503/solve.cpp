#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
#include<climits>
#include<deque>

using namespace std;

int m,INF=30000000;
stack<int,vector<int> >A,B,C;
stack<int,vector<int> >A2,B2,C2;

int func(string p){
  
  int cnt=0;

  for(int i=0;i<m;i++){
    
    if(B.empty() && (C.empty()||A.empty()))return cnt;
    
    if(!A.empty() && (B.empty() || A.top()>=B.top()) && p!="BA"){
      B.push(A.top());
      A.pop();
      cnt++,p="AB";
    }
    
    if(!B.empty() && (C.empty() || B.top()>=C.top()) && p!="CB"){
      C.push(B.top());
      B.pop();
      cnt++,p="BC";
    }
    
    if(!B.empty() && (A.empty() || B.top()>=A.top()) && p!="AB"){
      A.push(B.top());
      B.pop();
      cnt++,p="BA";
    }
    
    if(!C.empty() && (B.empty() || C.top()>=B.top()) && p!="BC"){
      B.push(C.top());
      C.pop();
      cnt++,p="CB";
    }
    
  }

  return INF;
}

int main(void){
  int n,ans,s,t;
  
  while(cin >> n >> m,n|m){
    while(!A.empty())A.pop();
    while(!B.empty())B.pop();
    while(!C.empty())C.pop();
    while(!A2.empty())A2.pop();
    while(!B2.empty())B2.pop();
    while(!C2.empty())C2.pop();


    cin >> s;
    for(int i=0;i<s;i++){
      cin >> t;
      A.push(t);
    }
    cin >> s;
    for(int i=0;i<s;i++){
      cin >> t;
      B.push(t);
    }
    cin >> s;
    for(int i=0;i<s;i++){
      cin >> t;
      C.push(t);
    }
    
    A2=A,B2=B,C2=C;
    ans=func("CB");
    
    A=A2,B=B2,C=C2;
    ans=min(ans,func("AB"));
    
    A=A2,B=B2,C=C2;
    ans=min(ans,func("BA"));
    
    A=A2,B=B2,C=C2;
    ans=min(ans,func("BC"));
    
    if(ans==INF)cout << -1 << endl;
    else cout << ans << endl;

  }
  return 0;
}

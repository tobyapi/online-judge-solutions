#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
 
using namespace std;
 
typedef long long ll;
typedef pair <int,vector<int> > P;
 
static const double EPS = 1e-8;

static const int tx[] = {0,1,0,-1};
static const int ty[] = {-1,0,1,0};

vector<int> compute_union(const vector<int>& A,const vector<int>& B){
  set<int> tmp;
  for(int i = 0; i < A.size(); i++){
    tmp.insert(A[i]);
  }
  for(int i = 0; i < B.size(); i++){
    tmp.insert(B[i]);
  }
  vector<int> res;
  for(set<int>::iterator it = tmp.begin(); it != tmp.end(); it++){
    res.push_back(*it);
  }
  return res;
}

vector<int> compute_intersection(const vector<int>& A,const vector<int>& B){
  set<int> tmp;
  for(int i = 0; i < A.size(); i++){
    for(int j = 0; j < B.size(); j++){
      if(A[i] == B[j]){
	tmp.insert(A[i]);
      }
    }
  }
  vector<int> res;
  for(set<int>::iterator it = tmp.begin(); it != tmp.end(); it++){
    res.push_back(*it);
  }
  return res;
}

vector<int> compute_difference(const vector<int>& A,const vector<int>& B){
  set<int> tmp;
  for(int i = 0; i < A.size(); i++){
    bool isok = true;
    for(int j = 0; j < B.size(); j++){
      if(A[i] == B[j]){
	isok = false;
      }
    }
    if(isok){
      tmp.insert(A[i]);
    }
  }

  vector<int> res;
  for(set<int>::iterator it = tmp.begin(); it != tmp.end(); it++){
    res.push_back(*it);
  }
  return res;
}

vector<int> compute_symmetric_difference(const vector<int>& A,const vector<int>& B){
  vector<int> intersection = compute_intersection(A,B);
  vector<int> diff_a = compute_difference(A,intersection);
  vector<int> diff_b = compute_difference(B,intersection);
  return compute_union(diff_a,diff_b);
}

vector<int> compute_complement(const vector<int>& A,const vector<int>& U){
  vector<int> intersection = compute_intersection(A,U);
  return compute_difference(U,intersection);
}

P factor(const string& str,const vector<int>& U, int pos);
P term(const string& str,const vector<int>& U, int pos);
vector<int> numbers[256];
vector<int> U;

P factor(const string& str,const vector<int>& U, int pos){
  vector<int> current_set;

  P r1 = term(str,U,pos);
  pos = r1.first;
  current_set = r1.second;
  while(pos < str.size()
	&& (str[pos] == 'u' || str[pos] == 'i'
	    || str[pos] == 'd' || str[pos] == 's')){
    P r2 = term(str,U,pos+1);
    if(str[pos] == 'u'){
      current_set = compute_union(current_set,r2.second);
      pos = r2.first;
    }
    else if(str[pos] == 'i'){
      current_set = compute_intersection(current_set,r2.second);
      pos = r2.first;
    }
    else if(str[pos] == 'd'){
      current_set = compute_difference(current_set,r2.second);
      pos = r2.first;
    }
    else if(str[pos] == 's'){
      current_set = compute_symmetric_difference(current_set,r2.second);
      pos = r2.first;
    }
  }
  return P(pos,current_set);
}

P term(const string& str, const vector<int>& U, int pos){
  if(str[pos] == '('){
    P r = factor(str,U,pos+1);
    pos = r.first;
    pos++;
    return P(pos,r.second);
  }
  else if(str[pos] == 'c'){
    P r = term(str,U,pos+1);
    return P(r.first,compute_complement(r.second,U));
  }
  else if(str[pos] == 'A' || str[pos] == 'B'
	  || str[pos] == 'C' || str[pos] == 'D'
	  || str[pos] == 'E'){
    return P(pos+1,numbers[str[pos]]);
  }
}

int main(){
  while(1){
    char alphabet[8];
    int num_of_elements;
    while(cin >> alphabet >> num_of_elements){

      if(alphabet[0] == 'R' && num_of_elements == 0){
  	break;
      }
      for(int element_i = 0; element_i < num_of_elements; element_i++){
  	int num;
  	cin >> num;
  	numbers[alphabet[0]].push_back(num);
      }
      U = compute_union(numbers[alphabet[0]],U);
    }

    string text;
    //cin >> text;
    if(!(cin >> text))break;
    P r = factor(text,U,0);
    vector<int> result = r.second;
    if(result.size() == 0){
      printf("NULL");
    }
    else{
      for(int i = 0; i < result.size(); i++){
  	printf("%s%d", i == 0 ? "" : " ", result[i]);
      }
    }
    printf("\n");

    for(int i = 0; i < 256; i++){
      numbers[i].clear();
    }

    U.clear();
    if(cin.eof()) break;
  }
}

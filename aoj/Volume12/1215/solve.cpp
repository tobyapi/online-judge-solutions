#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
 
#define FOUND 1
#define NOT_FOUND -1
 
bool compare(string s1, string s2){
  if(s1.size() == s2.size()) return s1 < s2;
  return s1.size() < s2.size();
} 
 
int main(){
  string in, sub;
  string seq;
  bool flag = true;
  while(getline(cin, in)){
    if(!flag && (in.size() == 0 || cin.eof())){
      if(cin.eof()) sub += in;   
      flag = true;
       
      map<char, int > mp;
      set<char> data;
 
      for(int i = 0 ; i < sub.size() ; i++) data.insert(sub[i]);
      for(int i = 0 ; i < sub.size() ; i++) mp[ sub[i] ] = NOT_FOUND;
       
      int ans = 0;
      int len = (1<<29);
      string ans2;
       
      for(int i = 0 ; i < seq.size() ; i++){
    if(data.find(seq[i]) == data.end()) continue;
    mp[ seq[i] ] = i;
     
    int left = (1<<29);
    bool ok = true;
    for(int j = 0 ; j < sub.size() ; j++){
      if(mp[ sub[j] ] == NOT_FOUND){
        ok = false;
        break;
      }
      left = min(left, mp[ sub[j] ]);
    }
     
    if(!ok) continue;
     
    if(i - left == len) ans++;
    if(i - left < len){
      len = i - left;
      ans = 1;
      //cout << "i = " << i << " left = " << left << endl;
      //cout << i << endl;
      ans2 = seq.substr(left, i-left+1);
      //cout << seq.substr(left, i-left+1) << endl;
    }
     
      }
       
      cout << ans << endl << endl;
      if(ans != 0){
    for(int i = 0 ; i < ans2.size() ; i += 72){
      cout << ans2.substr(i, 72) << endl;
    }
    if(!cin.eof()) cout << endl;
      }
 
      //cout << "ans_len = " << len << endl;
      //cout << "ans_cnt = " << ans << endl;
      //cout << "seq = " << seq << endl;
      //cout << "sub = " << sub << endl;
      //cout << endl;
      seq = "", sub = "";
      continue;
    }
    else if(flag && in.size() != 0){
      seq += in;
      continue;
    }
    else if(flag && in.size() == 0){
      flag = false;
      continue;
    }
    else if(!flag && in.size() != 0){
      sub += in;
      continue;
    }
   
     
 
  }
   
  return 0;
}

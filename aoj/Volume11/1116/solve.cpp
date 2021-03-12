#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<bitset>
#include<cmath>
#include<set>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<28)
 
using namespace std;
 
struct Puzzle
{
  char t,r,b,l;
  Puzzle(char t='$',char r='$',char b='$',char l='$'):t(t),r(r),b(b),l(l){}
 
  void rotate90()
  {
    char tmp = t;
    t = l;
    l = b;
    b = r;
    r = tmp;
  }
 
  bool operator < (const Puzzle &p)const
  {
    if(t != p.t)return t < p.t;
    if(r != p.r)return r < p.r;
    if(b != p.b)return b < p.b;
    return l < p.l;
  }
 
};
 
Puzzle puzzle[9];
Puzzle p2[9];
int cnt;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
 
 
bool match(char a,char b)
{
  if(a == 'R' && b == 'r')return true;
  if(a == 'G' && b == 'g')return true;
  if(a == 'B' && b == 'b')return true;
  if(a == 'W' && b == 'w')return true;
  if(a == 'w' && b == 'W')return true;
  if(a == 'b' && b == 'B')return true;
  if(a == 'g' && b == 'G')return true;
  if(a == 'r' && b == 'R')return true;
    return false;
}
 
void dfs(int p,int used)
{
 
  if(p >= 9)
    {
      cnt++;
      return;
    }
 
  rep(i,9)
    {
      if((used >> i) & 1)continue;
      puzzle[p] = p2[i];
      rep(j,4)
    {
      if(p == 0)
        {
          dfs(p+1,used|(1<<i));
          puzzle[p].rotate90();
          continue;
        }
 
      if(p%3 == 0)
        {
          if(match(puzzle[p].t,puzzle[p-3].b))
        {
          dfs(p+1,used|(1<<i));
        }
        }
      else
        {
          bool ok = true;
          if(p-3>=0)
        if(!match(puzzle[p].t,puzzle[p-3].b))ok = false;
          if(!match(puzzle[p].l,puzzle[p-1].r))ok = false;
          if(ok)
        {
          dfs(p+1,used|(1<<i));
        }
        }
      puzzle[p].rotate90();
    }
    }
 
}
 
int main()
{
  int T;
  cin >> T;
  while(T--)
    {
      cnt = 0;
      rep(i,3)
    {
      rep(j,3)
        {
          string s;
          cin >> s;
          p2[i*3+j].t = s[0];
          p2[i*3+j].r = s[1];
          p2[i*3+j].b = s[2];         
          p2[i*3+j].l = s[3];         
        }
    }
      dfs(0,0);
 
      cout << cnt << endl;
    }
  return 0;
}

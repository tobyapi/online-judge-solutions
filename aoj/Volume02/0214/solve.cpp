#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>

using namespace std;

double EPS = 1e-10;
const double PI = acos(-1);

double add(double a, double b){
if(abs(a+b) < EPS * (abs(a)+abs(b)))return 0;
return a+b;
}

struct point{
double x, y;
point(){}
point(double x,double y) : x(x) , y(y){}

point operator + (point p){
return point(add(x,p.x), add(y,p.y));
}

point operator - (point p){
return point(add(x,-p.x), add(y,-p.y));
}

point operator * (double d){
return point(x*d,y*d);
}

point operator / (double d){
return point(x/d,y/d);
}

bool operator == ( const point &p ) const {
return abs(x-p.x) < EPS && abs(y-p.y) < EPS;
}
};

double dot(point a, point b) {
return (a.x * b.x + a.y * b.y);
}

double cross(point a, point b) {
return (a.x * b.y - a.y * b.x);
}

int is_point_on_line(point a, point b, point c) {
return cross(a-c, b-c)==0 && dot(a-c, b-c)<=0;
}

int is_intersected_ls(point a1, point a2, point b1, point b2) {

if(cross(a1-a2,b1-b2)==0){
return is_point_on_line(a1,a2,b1) || is_point_on_line(a1,a2,b2)
|| is_point_on_line(b1,b2,a1) || is_point_on_line(b1,b2,a2);
}
else {
return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}
}

int inside(point p, vector<point> ps){
point a,b;
a=b=p;
b.x=DBL_MAX;
int n=ps.size();
ps.push_back(ps[0]);
double ymx=-DBL_MAX,ymn=DBL_MAX;
for(int i=0;i<n;i++){
ymx=max(ymx,ps[i].y);
ymn=min(ymn,ps[i].y);
}
if(a.y<=ymn||a.y>=ymx)return 0;

for(int i=0;i<n;i++){
if(is_point_on_line(ps[i],ps[i+1],p))return 1;
}

int cnt1=0;
for(int i=0;i<n;i++)
if(is_point_on_line(a,b,ps[i]))cnt1++;

int cnt=0;
for(int i=0;i<n;i++)
if(is_intersected_ls(ps[i],ps[i+1],a,b))cnt++;

return (cnt-cnt1)%2;
}

int crossPol(vector<point> pol1, vector<point> pol2){
int szpol1=pol1.size();
int szpol2=pol2.size();

for(int i=0;i<szpol1;i++)
if(inside(pol1[i],pol2))return 1;

for(int i=0;i<szpol2;i++)
if(inside(pol2[i],pol1))return 1;

pol1.push_back(pol1[0]);
pol2.push_back(pol2[0]);

for(int i=0;i<szpol1;i++)
for(int j=0;j<szpol2;j++)
if(is_intersected_ls(pol1[i],pol1[i+1],pol2[j],pol2[j+1]))return 1;

return 0;
}

int gr[101][101],fg[101],m;

void dfs(int j){
fg[j]=1;
for(int k=0;k<m;k++)
if(gr[j][k]==1 && !fg[k])dfs(k);
}

int main(void){
int n;
point a;
vector<point>pol[101];

while(cin >> n,n){

for(int i=0;i<n;i++){
cin >> m;

for(int i=0;i<101;i++)pol[i].clear();

for(int i=0;i<101;i++){
for(int j=0;j<101;j++){
gr[i][j]=0;
}
fg[i]=0;
}

for(int j=0;j<m;j++){
for(int k=0;k<4;k++){
cin >> a.x >> a.y;
pol[j].push_back(a);
}
}

for(int j=0;j<m;j++){
for(int k=0;k<m;k++){
if(j!=k && crossPol(pol[j],pol[k]))gr[j][k]=gr[k][j]=1;
}
}

int cnt=0;
for(int j=0;j<m;j++){
if(fg[j]==0){
dfs(j);
cnt++;
}
}

cout << cnt << endl;
}
}
return 0;
}

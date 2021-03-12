#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<set>

#define all(c) (c).begin(),(c).end()

using namespace std;

#define curr(P, i) P[(i) % P.size()]
#define next(P, i) P[(i+1) % P.size()]

using namespace std;

typedef pair<int,int> Pint;

double EPS = 1e-12;
const double PI = acos(-1);

double add(double a, double b){
  if(abs(a+b) < EPS * (abs(a)+abs(b)))return 0;
  return a+b;
}

struct point{
  double x, y;
  point(){}
  point(double x,double y) : x(x) , y(y){}
  point operator + (point p){return point(add(x,p.x), add(y,p.y));}
  point operator - (point p){return point(add(x,-p.x), add(y,-p.y));}
  point operator * (double d){return point(x*d,y*d);}
  bool operator == (point p){return abs(x-p.x)<EPS && abs(y-p.y)<EPS;}
  bool operator < (const point &p) const {
    if(p.x != x)return x<p.x;
    return y < p.y;
  }
};

typedef point Vector;
typedef pair<point,point> Line;
typedef vector<point> Polygon;

class Segment{
public:
  point p1, p2;
  Segment(){}
  Segment(point p1,point p2):p1(p1), p2(p2){}
};


double dot(point a, point b){return (a.x*b.x+a.y*b.y);}
double cross(point a, point b){return (a.x*b.y-a.y*b.x);}
double norm(point a){return sqrt(dot(a,a));}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw( point p0, point p1, point p2 ){
  Vector a=p1-p0;
  Vector b=p2-p0;
  if (cross(a,b)>EPS) return COUNTER_CLOCKWISE;
  if (cross(a,b)<-EPS) return CLOCKWISE;
  if (dot(a, b)<-EPS) return ONLINE_BACK;
  if (norm(a)<norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isOnSegment(point a, point b, point c) {
  if ( a==c || b==c ) return true;
  return (norm(a-c)+norm(c-b) < norm(a-b)+EPS );
}

bool isIntersect(point p1, point p2, point p3, point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool isIntersect(Segment s1, Segment s2){
  return isIntersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

point getCrossPoint(Segment s1, Segment s2){
  assert(isIntersect(s1,s2));
  // for boundary touch (end-point to end-point)
  if ( s1.p1 == s2.p1 ) return s1.p1;
  if ( s1.p1 == s2.p2 ) return s1.p1;
  if ( s1.p2 == s2.p1 ) return s1.p2;
  if ( s1.p2 == s2.p2 ) return s1.p2;
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1/(d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1)*t;
}

/*
  点多角形包含判定
  out 0
  in 1
  on 2
*/
int contain(point p,vector<point>pol){
  bool in=false;
  for(int i=0;i<pol.size();i++){
    point a=curr(pol,i)-p,b=next(pol,i)-p;
    if(a.y>b.y)swap(a,b);
    if(a.y<EPS && EPS<b.y && cross(a,b)<EPS)in=!in;
       if(abs(cross(a,b))<EPS && dot(a,b)<EPS)return 2;
  }
 return in?1:0;
}
  
  /*
    線分アレンジメント
    引数
    vector<Segment>S 線分の集合
    vector<point>&P Sの全ての交点を入れる配列。最初は空で渡す。
    戻り値
    vector<vector<int> >G 無向グラフ。
  */
  vector<vector<int> > segmentArrangement(vector<Segment>S,vector<point> &P){
    P.clear();
    //交点を列挙してソートしてユニークする
    for(int i=0;i<S.size()-1;i++){
      P.push_back(S[i].p1);
      P.push_back(S[i].p2);
      for(int j=i+1;j<S.size();j++){
	if(!isIntersect(S[i],S[j]))continue;
	P.push_back(getCrossPoint(S[i],S[j]));
      }
    }
    
    sort(all(P));
    P.erase(unique(all(P)),P.end());
    
    /*
      線分の端点を始点として
      線分の上にある交点に辺を張る
    */
    vector<vector<int> >G(P.size());
    for(int i=0;i<S.size();i++){
      vector<pair<double,int> >L;
      
      //線分の上にある交点を列挙
      for(int j=0;j<P.size();j++)
	if(ccw(S[i].p1,S[i].p2,P[j])==ON_SEGMENT)
	  L.push_back(make_pair(norm(S[i].p1-P[j]),j));
      
      //端点からの距離でソート
      sort(all(L));
      
      //グラフを構築
      for(int j=0;j+1<L.size();j++){
	int a = L[j].second;
	int b = L[j+1].second;
	G[a].push_back(b);
	G[b].push_back(a);
      }
    }
    
    
    //偏角ソート
    for(int i=0;i<G.size();i++){
      for(int j=G[i].size()-2;j>=0;j--){
	for(int k=0;k<=j;k++){
	  int e1=G[i][k],e2=G[i][k+1];
	  double angle1=atan2(P[e1].y-P[i].y,P[e1].x-P[i].x);
	  double angle2=atan2(P[e2].y-P[i].y,P[e2].x-P[i].x);
	  if(angle1>angle2)swap(G[i][k],G[i][k+1]);
	}
      }
    }
    return G;
  }
  
  bool ans;
  /*
    グラフの閉路を検出して多角形として経路を復元。
    G グラフ
    V 使った辺
    P 線分の交点
  */
  void parse(vector<vector<int> >&G,int s,int t,set<Pint>&V,vector<point> &P){
    int v=s,u=t;
    vector<int>p;
    
    while(true){
      //経路復元
      if(V.count(make_pair(v,u))){
	reverse(p.begin(),p.end());
	vector<point>pol;
	for(int i=0;i<p.size();i++)pol.push_back(P[p[i]]);
	if(contain(point(0,0),pol)==1)ans=true;
	break;
      }
      p.push_back(v);
      V.insert(make_pair(v,u));
      int nx;
      for(int i=0;i<G[u].size();i++){
	if(G[u][i]==v){nx=i;break;}
      }
      nx=(nx+1)%G[u].size();
      v=u,u=G[u][nx];
    }
  }
  
  int main(void){
    
    int n;
    while(cin >> n,n){
      vector<Segment>Seg(n);
      for(int i=0;i<n;i++){
	cin >> Seg[i].p1.x >> Seg[i].p1.y;
	cin >> Seg[i].p2.x >> Seg[i].p2.y;
      }
      vector<point>P;
      vector<vector<int> >G=segmentArrangement(Seg,P);
      set<Pint>V;
      
      ans=false;
      for(int i=0;i<G.size();i++){
	for(int j=0;j<G[i].size();j++){
	  int to=G[i][j];
	  if(i==to)continue;
	  if(V.count(make_pair(i,to))==0)parse(G,i,to,V,P);
	}
      }
      if(ans)cout << "yes" << endl;
      else cout << "no" << endl;
    }
    return 0;
 }
  
  

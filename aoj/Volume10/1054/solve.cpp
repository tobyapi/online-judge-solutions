#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>

using namespace std;

struct point{
  double x, y;
};

struct button{
  point ld,ru;
  string name;
};

struct page{
  string name;
  vector<button>btn;   
}; 

int main(void){
  int n;
  int w,h,b;
  point l,r;
  page in;
  vector<page> a;
  button tmp;

  while(cin >> n,n){
  
    a.clear();

    cin >> w >> h;
    
    for(int j=0;j<n;j++){
      in.btn.clear();
      cin >> in.name >> b;    
      
      for(int i=0;i<b;i++){
	cin >> tmp.ld.x >> tmp.ld.y >> tmp.ru.x >> tmp.ru.y >> tmp.name;
	in.btn.push_back(tmp);
      }
      a.push_back(in);
    }

    int m,now=0,fg=0;
    static page buf[1000000];

    cin >> m;
    buf[0]=a[0];

    for(int k=0;k<m;k++){
      string s;
      cin >> s;
      
      if(s=="click"){
	int c,d;
	cin >> c >> d;
	
	for(int i=0;i<buf[now].btn.size();i++){
	  int fg2=0;
	  if(buf[now].btn[i].ld.x <=c &&
	     buf[now].btn[i].ld.y <=d &&
	     buf[now].btn[i].ru.x >=c &&
	     buf[now].btn[i].ru.y >=d){
	    for(int j=0;j<a.size();j++){
	      if(buf[now].btn[i].name==a[j].name){
		buf[++now]=a[j];
		fg=0;
		fg2=1;
		break;
	      }
	    }
	    if(fg2)break;
	  }
	}
      }
      else if(s=="back" && now>0){
	now--;
	fg++;
      }
      else if(s=="forward" && fg>0 && now < 1000000)now++,fg--;
      else if(s=="show")cout << buf[now].name << endl;
    }
  }

  return 0;
}

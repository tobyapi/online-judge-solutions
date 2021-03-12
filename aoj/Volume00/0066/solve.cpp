#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
  char grid[3][3];
  
  while(true){
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
	if(scanf(" %c",&grid[i][j])==EOF)return 0;
    
    if(grid[0][0]=='o'&&grid[1][1]=='o'&&grid[2][2]=='o'){
      cout << 'o' << endl;
      continue;
    }
    if(grid[0][2]=='o' && grid[1][1]=='o' && grid[2][0]=='o'){
      cout << 'o' << endl;
      continue;
    }
    if(grid[0][0]=='x'&&grid[1][1]=='x'&&grid[2][2]=='x'){
      cout << 'x' << endl;
      continue;
    }
    if(grid[0][2]=='x' && grid[1][1]=='x' && grid[2][0]=='x'){
      cout << 'x' << endl;
      continue;
    }

    int fg=0;
    for(int i=0;i<3;i++){
      if(grid[i][0]=='o'&&grid[i][1]=='o'&&grid[i][2]=='o'){
	cout << "o" << endl;
	fg=1;
	break;
      }
      else if(grid[i][0]=='x'&&grid[i][1]=='x'&&grid[i][2]=='x'){
	cout << "x" << endl;
	fg=1;
	break;
      }
      else if(grid[0][i]=='o'&&grid[1][i]=='o'&&grid[2][i]=='o'){
	cout << "o" << endl;
	fg=1;
	break;
      }
      else if(grid[0][i]=='x'&&grid[1][i]=='x'&&grid[2][i]=='x'){
	cout << "x" << endl;
	fg=1;
	break;
      }

    }
    if(!fg)cout << 'd' << endl;
  }
  return 0;
}

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=100;
struct node{
	int x,y;
	int step;
}T,S;
int n,m;
char matrix[maxn][maxn];
bool inq[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool judge(int x,int y){
	if(x>=n || x<0 || y>=m || y<0) return false;
	if(matrix[x][y]=='*' || inq[x][y]==true) return false;
	return true;
}
int BFS(){
	queue<node> Q;
	node tmp;
	Q.push(S);
	inq[S.x][S.y]=true;
	while(!Q.empty()){
		node top=Q.front();
		if(top.x==T.x && top.y==T.y)
			return top.step;
		Q.pop();
		for(int i=0;i<4;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(judge(newX,newY)){
				tmp.x=newX;
				tmp.y=newY;
				tmp.step=top.step+1;
				Q.push(tmp);
				inq[newX][newY]=true;
			}
		}
	}//while
	return -1;
}
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar();
		for(int j=0;j<m;j++){
			matrix[i][j]=getchar();
		}
		matrix[i][m+1]='\0';
	}
	scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
	S.step=0;
	printf("%d\n",BFS());
	return 0;
}
/*
Sameple Input
5 5
.....
.*.*.
.*S*.
.***.
...T*
2 2 4 3
Sample Output
11
*/
#include <iostream>
#include <queue>
using namespace std;
const int maxn=100;
struct node{
	int x,y;
};
int n,m;
int matrix[maxn][maxn];
bool inq[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool judge(int x,int y){
	if(x>=n || x<0 || y>=m || y<0) return false;
	if(matrix[x][y]==0 || inq[x][y]==true) return false;
	return true;
}
void BFS(int x,int y){
	queue<node> Q;
	node temp;
	temp.x=x;
	temp.y=y;
	Q.push(temp);
	inq[x][y]=true;
	while(!Q.empty()){
		node top=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(judge(newX,newY)){
				temp.x=newX;
				temp.y=newY;
				Q.push(temp);
				inq[newX][newY]=true;
			}
		}//for
	}//while
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&matrix[i][j]);
		}
	int ans=0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(matrix[x][y]==1 && inq[x][y]==false){
				ans++;
				BFS(x,y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
Input
6 7
0 1 1 1 0 0 1
0 0 1 0 0 0 0
0 0 0 0 1 0 0
0 0 0 1 1 1 0
1 1 1 0 1 0 0
1 1 1 1 0 0 0
Output
4
*/
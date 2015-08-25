#include <iostream>
using namespace std;
const int maxn=100;
struct node{
	int x,y;
};
int n,m;
int matrix[maxn][maxn];
bool ind[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool judge(int x,int y){
	if(x>=n || x<0 || y>=m || y<0) return false;
	if(matrix[x][y]==0 || ind[x][y]==true) return false;
	return true;
}
void DFS(int x,int y){
	ind[x][y]=true;
	for(int i=0;i<4;i++){
		int newX=x+X[i];
		int newY=y+Y[i];
		if(judge(newX,newY)){
			DFS(newX,newY);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int x=0;x<n;x++)
		for(int y=0;y<m;y++)
			scanf("%d",&matrix[x][y]);
	int ans=0;
	for(int x=0;x<n;x++)
		for(int y=0;y<m;y++){
			if(matrix[x][y]==1 && ind[x][y]==false){
				ans++;
				DFS(x,y);
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
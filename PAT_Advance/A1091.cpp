#include <iostream>
#include <queue>
using namespace std;
struct node{
	int x,y,z;
};
int m,n,slice,T;
int matrix[1287][129][61];
bool inq[1287][129][61]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool judge(int x,int y,int z){
	if(x>=m || x<0 || y>=n || y<0 || z>=slice || z<0) return false;
	if(matrix[x][y][z]==0 || inq[x][y][z]==true) return false;
	return true;
}
int BFS(int x,int y,int z){
	int count=0;
	node tmp;
	queue<node> Q;
	tmp.x=x,tmp.y=y,tmp.z=z;
	Q.push(tmp);
	inq[x][y][z]=true;
	while(!Q.empty()){
		node top=Q.front();
		Q.pop();
		count++;
		for(int i=0;i<6;i++){
			int X1,Y1,Z1;
			X1=top.x+X[i];
			Y1=top.y+Y[i];
			Z1=top.z+Z[i];
			if(judge(X1,Y1,Z1)){
				tmp.x=X1,tmp.y=Y1,tmp.z=Z1;
				Q.push(tmp);
				inq[X1][Y1][Z1]=true;
			}
		}
	}
	return count<T ? 0 : count;
}
int main()
{
	scanf("%d%d%d%d",&m,&n,&slice,&T);
	for(int z=0;z<slice;z++)
		for(int x=0;x<m;x++)
			for(int y=0;y<n;y++)
				scanf("%d",&matrix[x][y][z]);
	int ans=0;
	for(int z=0;z<slice;z++)
		for(int x=0;x<m;x++)
			for(int y=0;y<n;y++){
				if(matrix[x][y][z]==1 && inq[x][y][z]==false){
					ans+=BFS(x,y,z);
				} 
			}
	printf("%d\n",ans);
	return 0;
}
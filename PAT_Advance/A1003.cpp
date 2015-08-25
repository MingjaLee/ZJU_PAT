#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=505;
const int INF=0x3fffffff;
int G[N][N];
int dist[N],team[N],teamMost[N],num[N];
bool visit[N]={false};
int n,m,c1,c2;
void Input(){
	for(int i=0;i<n;i++)
		scanf("%d",&team[i]);		
	int L,u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&L);
		G[u][v]=G[v][u]=L;
	}
}
void Init(){
	fill(dist,dist+n,INF);
	memset(teamMost,0,sizeof(teamMost));
	memset(num,0,sizeof(num));
}
void Dijistra(){
	Init();
	dist[c1]=0;
	num[c1]=1;
	teamMost[c1]=team[c1];
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(visit[j]==false && MIN>dist[j]){
				MIN=dist[j];
				u=j;
			}
		}
		if(u==-1 || u==c2) return;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(visit[v]==false){
				int distcost=dist[u]+G[u][v];
				if(distcost<dist[v]){
					dist[v]=distcost;
					teamMost[v]=teamMost[u]+team[v];
					num[v]=num[u];
				}
				else if(distcost==dist[v]){
					num[v]+=num[u];
					if(teamMost[v]<teamMost[u]+team[v])
						teamMost[v]=teamMost[u]+team[v];
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	fill(G[0],G[0]+N*N,INF);
	Input();
	Dijistra();
	printf("%d %d\n",num[c2],teamMost[c2]);
	return 0;
}
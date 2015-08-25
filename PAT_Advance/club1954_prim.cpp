#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=101;
const int INF=1<<30;
int G[N][N],dist[N];
bool visit[N];
int NumRoad,NumVillage;
void Init(){
	fill(dist,dist+N,INF);
	fill(visit,visit+N,0);
}
int prim(int s){
	Init();
	dist[s]=0;
	int ans=0;
	for(int i=0;i<NumVillage;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=NumVillage;j++){
			if(!visit[j] && dist[j]<MIN)
				MIN=dist[u=j];
		}
		if(u==-1) return -1;
		visit[u]=true;
		ans+=dist[u];
		for(int v=1;v<=NumVillage;v++){
			if(!visit[v] && G[u][v]!=INF && G[u][v]<dist[v])
				dist[v]=G[u][v];
		}
	}	
	return ans;
}
int main()
{
	while(scanf("%d%d",&NumRoad,&NumVillage)!=EOF){
		if(NumRoad==0) break;
		int u,v,w;
		fill(G[0],G[0]+N*N,INF);
		for(int i=0;i<NumRoad;i++){
			scanf("%d%d%d",&u,&v,&w);
			G[u][v]=G[v][u]=w;
		}
		int ans=prim(1);
		if(ans!=-1)
			printf("%d\n",ans);
		else
			printf("?\n");
	}
	return 0;
}
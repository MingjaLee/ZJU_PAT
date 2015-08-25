#include <iostream>
#include <algorithm>
using namespace std;
const int N=55;
const int INF=1<<30;
int G[N][N];
int dist[N];
bool visit[N]={false};
int n,st;
void Dijistra(int s){
	fill(dist,dist+N,INF);
	dist[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(!visit[j] && dist[j]<MIN)
				MIN=dist[u=j];
		}
		if(MIN==INF) return;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(!visit[v] && G[u][v]!=0 && dist[u]+G[u][v]<dist[v]){
				dist[v]=dist[u]+G[u][v];
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&st);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	}
	Dijistra(st);
	int count=0;
	for(int i=0;i<n;i++){
		if(i==st) continue;
		if(dist[i]==INF)
			printf("-1 ");
		else 
			printf("%d ",dist[i]);
	}
	printf("\n");
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int N=505;
const int INF=1<<29;
int G[N][N],cost[N][N];
int Mincost[N],pre[N],dist[N];
bool visit[N]={false};
int n,m,s,d;
void Init(){
	for(int i=0;i<N;i++){
		pre[i]=i;
		dist[i]=INF;
		Mincost[i]=INF;
	}
}
void Dijistra(){
	Init();
	dist[s]=Mincost[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(visit[j]==false && dist[j]<MIN){
				MIN=dist[j];
				u=j;
			}
		}
		if(MIN==INF || u==d) return;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(visit[v]==false && G[u][v]!=INF){
				int distcost=dist[u]+G[u][v];
				if(distcost<dist[v]){
					dist[v]=distcost;
					Mincost[v]=Mincost[u]+cost[u][v];
					pre[v]=u;
				}
				else if(distcost==dist[v] && Mincost[u]+cost[u][v]<Mincost[v]){
					Mincost[v]=Mincost[u]+cost[u][v];
					pre[v]=u;
				}
			}
		}
	}
}
void DFS(int start,int v){
	if(v==s){
		printf("%d",s);
		return;
	}
	DFS(start,pre[v]);
	printf(" %d",v);
}
void Put_Path(){
	stack<int> p;
	int v=d;
	while(v!=s){
		p.push(v);
		v=pre[v];
	}
	printf("%d",s);
	while(!p.empty()){
		printf(" %d",p.top());
		p.pop();
	}
}
int main()
{
	int u,v;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	fill(G[0],G[0]+N*N,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d%d",&G[u][v],&cost[u][v]);
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];
	}
	Dijistra();
	//DFS(s,d);
	Put_Path();
	printf(" %d %d\n",dist[d],Mincost[d]);
	return 0;
}
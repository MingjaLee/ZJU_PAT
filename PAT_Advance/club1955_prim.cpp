#include <iostream>
#include <algorithm>
using namespace std;
const int N=101;
const int INF=1<<30;
int G[N][N],dist[N],n;
bool visit[N];
void Init(){
	fill(dist,dist+N,INF);
	fill(visit,visit+N,0);
}
int Prim(int s){
	Init();
	dist[s]=0;
	int ans=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=n;j++){
			if(!visit[j] && dist[j]<MIN)
				MIN=dist[u=j];
		}
		if(u==-1) return -1;
		visit[u]=true;
		ans+=dist[u];
		for(int v=1;v<=n;v++){
			if(!visit[v] && G[u][v]!=INF && G[u][v]<dist[v])
				dist[v]=G[u][v];
		}
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)!=EOF && n!=0){
		int m=n*(n-1)/2;
		int u,v,w,flag;
		fill(G[0],G[0]+N*N,INF);
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&u,&v,&w,&flag);
			if(flag==1)
				G[u][v]=G[v][u]=0;
			else
				G[u][v]=G[v][u]=w;
		}
		int ans=Prim(1);
		printf("%d\n",ans);
	}
	return 0;
}
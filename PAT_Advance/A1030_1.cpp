#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=505;
const int INF=1<<30;
int G[N][N],cost[N][N];
int dist[N],Mincost[N];
int min_cost=INF;
bool visit[N];
vector<int> pre[N];
vector<int> path,tempPath;

int n,m,s,d;
void Init(){
	for(int i=0;i<N;i++){
		dist[i]=INF;
		Mincost[i]=INF;
		visit[i]=false;
		pre[i].push_back(i);
	}
}
void Dijistra(int s){
	Init();
	dist[s]=0;
	Mincost[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(!visit[j] && dist[j]<MIN){
				MIN=dist[j];
				u=j;
			}
		}
		if(MIN==INF || u==d) return;
		visit[u]=true;
		for(int v=0;v<n;v++){
			if(!visit[v] && G[u][v]!=INF){
				int distcost=dist[u]+G[u][v];
				if(distcost<dist[v]){
					dist[v]=distcost;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(distcost==dist[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v){
	if(v==s){
		tempPath.push_back(v);
		int tempCost=0;
		for(int i=tempPath.size()-1;i>0;i--){
			int id=tempPath[i],idNext=tempPath[i-1];
			tempCost+=cost[id][idNext];
		}
		if(tempCost<min_cost){
			min_cost=tempCost;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int main()
{
	int u,v;
	scanf("%d%d%d%d",&n,&m,&s,&d);
	fill(G[0],G[0]+N*N,INF);
	fill(cost[0],cost[0]+N*N,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d%d",&G[u][v],&cost[u][v]);
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];
	}
//	cout<<"1"<<endl;
	Dijistra(s);
//	cout<<"2"<<endl;
	DFS(d);
//	cout<<"3"<<endl;
	for(int i=path.size()-1;i>=0;i--){
		printf("%d ",path[i]);
	}
//	cout<<endl;
	printf("%d %d\n",dist[d],min_cost);
	return 0;
}
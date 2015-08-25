#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=502;
const int INF=1<<29;
int G[N][N],dist[N],weight[N];
bool visit[N]={false};
vector<int> pre[N];
vector<int> path,tempPath;
int Cmax,n,ed,m,minNeed=INF,minRemain=INF;
void Init(){
	for(int i=0;i<=n;i++)
		pre[i].push_back(i);
	fill(dist,dist+N,INF);
	fill(visit,visit+N,0);
	fill(G[0],G[0]+N*N,INF);
}
void DFS(int v){
	if(v==0){
		tempPath.push_back(v);
		int need=0,remain=0;
		for(int i=tempPath.size()-1;i>=0;i--){
			int id=tempPath[i];
			if(weight[id]>0){
				remain+=weight[id];
			}
			else{
				if(remain>abs(weight[id])){
					remain-=abs(weight[id]);
				}
				else{
					need+=abs(weight[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minNeed){
			minNeed=need;
			minRemain=remain;
			path=tempPath;
		}
		else if(need==minNeed && remain<minRemain){
			minRemain=remain;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}//v==0
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
void Dijistra(int s){
	dist[s]=0;
	for(int i=0;i<=n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<=n;j++){
			if(!visit[j] && dist[j]<MIN)
				MIN=dist[u=j];
		}
		if(u==-1) return;
		visit[u]=true;
		for(int v=0;v<=n;v++){
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
int main()
{
	scanf("%d%d%d%d",&Cmax,&n,&ed,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=Cmax>>1;		
	}
//	cout<<"1"<<endl;
	weight[0]=0;
	Init();
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
//	cout<<"2"<<endl;
	Dijistra(0);
//	cout<<"after Dij"<<endl;
	DFS(ed);
//	cout<<"after DFS"<<endl;
	printf("%d ",minNeed);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i!=0) printf("->");
	}
//	cout<<"after path"<<endl;
	printf(" %d\n",minRemain);
	return 0;
}
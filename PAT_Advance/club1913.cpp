#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=101;
const int INF=1<<30;
struct node{
	double x,y;
}V[N];
double G[N][N],dist[N];
bool visit[N];
int n;
double getDist(node a,node b){
	double ans;
	ans=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	ans=sqrt(ans);
	return ans;
}
double Prim(int s){
	fill(dist,dist+N,INF);
	//cout<<dist[0]<<endl;
	fill(visit,visit+N,0);
	dist[s]=0;
	double ans=0;
	for(int i=0;i<n;i++){
		int u=-1;
		double MIN=INF;
		for(int j=0;j<n;j++){
			if(!visit[j] && dist[j]<MIN)
				MIN=dist[u=j];
		}
		if(u==-1) return -1;
		visit[u]=true;
		ans+=dist[u];
		for(int v=0;v<n;v++){
			if(!visit[v] && G[u][v]!=INF && G[u][v]<dist[v])
				dist[v]=G[u][v];
		}
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)!=EOF && n!=0){
		int x,y;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&V[i].x,&V[i].y);
		}
		fill(G[0],G[0]+N*N,INF);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				G[i][j]=G[j][i]=getDist(V[i],V[j]);
			}
		}
		double ans=Prim(0);
		double k=(int)((ans+0.001)*100)*0.01;
		printf("%f\n",k);
	}
	return 0;
}
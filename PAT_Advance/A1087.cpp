#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>;
using namespace std;
const int N=201;
const int INF=1<<30;
int G[N][N],dist[N],weight[N];
bool visit[N];
int NumPath=0,Anshappy=-1;
double AnsAvg=-1;
map<string,int> Vindex;
map<int,string> Vcity;
vector<int> pre[N],tempPath,path;
int n,k,st,ed;
void Init(){
	fill(dist,dist+N,INF);
	fill(visit,visit+N,0);
	for(int i=0;i<n;i++)
		pre[i].push_back(i);
}
void Dijistra(int s){
	Init();
	dist[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(!visit[j] && dist[j]<MIN)
				MIN=dist[u=j];
		}
		if(u==-1 || u==ed) return;
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
	if(v==st){
		tempPath.push_back(v);
		NumPath++;
	//	cout<<"NumPath="<<NumPath<<endl;
		int size=tempPath.size();
		int temphappy=0;
		double tempavg=0;
		for(int i=size-1;i>=0;i--){
			int u=tempPath[i];
			temphappy+=weight[u];
			tempavg+=weight[u]*1.0/(size-1);
		}
		if(temphappy>Anshappy){
			Anshappy=temphappy;
			AnsAvg=tempavg;
			path=tempPath;
		}
		else if(temphappy==Anshappy && tempavg>AnsAvg){
			AnsAvg=tempavg;
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
	scanf("%d%d",&n,&k);
	string city;
	cin>>city;
	Vindex[city]=0;
	Vcity[0]=city;
	st=0;
	weight[st]=0;
//	cout<<city<<endl;
	for(int i=1;i<=n-1;i++){
		int w;
		cin>>city>>w;
		Vindex[city]=i;
		Vcity[i]=city;
		weight[i]=w;
	}
	ed=Vindex["ROM"];
	string city1,city2;
	fill(G[0],G[0]+N*N,INF);
	for(int i=0;i<k;i++){
		int u,v,w;
		cin>>city1>>city2>>w;
		u=Vindex[city1];
		v=Vindex[city2];
		G[u][v]=G[v][u]=w;
	}
//	cout<<"befor Dij"<<endl;
	Dijistra(st);
//	cout<<"after Dij"<<endl;
	DFS(ed);
//	cout<<"after DFS"<<endl;
	printf("%d %d %d %d\n",NumPath,dist[ed],Anshappy,(int)AnsAvg);
	for(int i=path.size()-1;i>=0;i--){
		int tmp=path[i];
		cout<<Vcity[tmp];
		if(i>0)
			printf("->");
		else
			printf("\n");
	}
	return 0;
}
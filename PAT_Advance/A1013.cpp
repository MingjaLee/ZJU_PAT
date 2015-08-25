#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N=1005;
vector<int> Adj[N];
bool inq[N];
int n,m,k;
void Init_inq(){
	for(int i=1;i<=n;i++)
		inq[i]=false;
}
void BFS(int u){
	queue<int> Q;
	Q.push(u);
	inq[u]=true;
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(int i=0;i<Adj[now].size();i++){
			int v=Adj[now][i];
			if(inq[v]==false){
				Q.push(v);
				inq[v]=true;
			}
		}
	}
}
int BFSTraveral(int lost){
	Init_inq();
	inq[lost]=true;
	int ret=0;
	for(int i=1;i<=n;i++){
		if(inq[i]==false){
			ret++;
			BFS(i);
		}
	}
	return ret-1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	int lost,need;
	for(int i=0;i<k;i++){
		scanf("%d",&lost);
		printf("%d\n",BFSTraveral(lost));
	}
	return 0;
}
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;
set<int> V;
map<int,bool> inq;
map<int,vector<int> > Adj;
void BFS(int u){
	queue<int> Q;
	Q.push(u);
	inq[u]=true;
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		int size=Adj[now].size();
		for(int i=0;i<size;i++){
			int v=Adj[now][i];
			if(inq[v]==false){
				Q.push(v);
				inq[v]=true;
			}
		}
	}
}
void BFSTraveral(){
	set<int>::iterator it;
	int ans=0;
	for(it=V.begin();it!=V.end();it++){
		if(inq[*it]==false){
			ans++;
			BFS(*it);
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		V.insert(a);
		V.insert(b);
		Adj[a].push_back(b);
		Adj[b].push_back(a);
		inq[a]=false;
		inq[b]=false;
	}
	BFSTraveral();
	return 0;
}
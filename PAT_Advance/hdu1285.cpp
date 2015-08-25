#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N=501;
vector<int> G[N];
int n,m,inDegree[N];
void Init(){
	for(int i=1;i<N;i++){
		inDegree[i]=0;
		G[i].clear();
	}
}
bool topologicalSort(){
	int num=0;
	priority_queue<int,vector<int>,greater<int> > Q;
	for(int i=1;i<=n;i++){
		if(inDegree[i]==0)
			Q.push(i);
	}
	while(!Q.empty()){
		int top=Q.top();
		Q.pop();
		printf("%d",top);
		if(++num!=n) printf(" ");
		else printf("\n");
		for(int i=0;i<G[top].size();i++){
			int next=G[top][i];
			if(--inDegree[next]==0)
				Q.push(next);
		}
		G[top].clear();
	}
	if(num!=n) return false;
	else return true;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		int u,v;
		Init();
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			inDegree[v]++;
		}
		topologicalSort();
	}
	return 0;
}

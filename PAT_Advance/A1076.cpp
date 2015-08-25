#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N=1005;
vector<int> Adj[N];
bool inq[N];
int n,L,k;
void Init_inq(){
	for(int i=1;i<=n;i++)
		inq[i]=false;
}
int BFS(int u){
	Init_inq();
	queue<int> Q;
	Q.push(u);
	inq[u]=true;
	int level=0,post=0;
	while(!Q.empty()){
		int now;
		queue<int> Q1;
		while(!Q.empty()){
			now=Q.front();
			Q.pop();
			for(int i=0;i<Adj[now].size();i++){
				int next=Adj[now][i];
				if(inq[next]==false){
					Q1.push(next);
					inq[next]=true;
					post++;
				}
			}
		}
		if(++level==L)
			return post;
		Q=Q1;
	}
	return post;
}
int main()
{
	scanf("%d%d",&n,&L);
	int m,follows;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&follows);
			Adj[follows].push_back(i);
		}
	}
	scanf("%d",&k);
	int user,ans;
	for(int i=0;i<k;i++){
		scanf("%d",&user);
		ans=BFS(user);
		printf("%d\n",ans);
	}
	return 0;
}
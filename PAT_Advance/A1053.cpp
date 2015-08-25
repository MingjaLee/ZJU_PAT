#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=110;
struct node{
	int weight;
	vector<int> child;
}Node[maxn];
int n,m,s;
int path[maxn];
bool cmp(int a,int b){
	return Node[a].weight>Node[b].weight;
}
void Create(){
	for(int i=0;i<n;i++)
		scanf("%d",&Node[i].weight);
	int ID,k,son;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&son);
			Node[ID].child.push_back(son);
		}
		sort(Node[ID].child.begin(),Node[ID].child.end(),cmp);
	}
	path[0]=0;
}
void Print_Path(int num){
	for(int i=0;i<num;i++){
		printf("%d",Node[path[i]].weight);
		if(i==num-1)
			printf("\n");
		else
			printf(" ");
	}
}
void DFS(int index,int numNode,int sum){
	if(sum>s) return;
	else if(sum==s){
		if(Node[index].child.size()!=0) return;
		else Print_Path(numNode);
	}
	else{
		for(int i=0;i<Node[index].child.size();i++){
			int child=Node[index].child[i];
			path[numNode]=child;
			DFS(child,numNode+1,sum+Node[child].weight);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	Create();
	DFS(0,1,Node[0].weight);
	return 0;
}
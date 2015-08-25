#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <vector>
#include <stack>
#include <set>
using namespace std;
const int N=105;
vector<int> child[N];
int n,m;
int maxL,maxSum=0;
void BFS(){
	queue<int> Q;
	Q.push(1);
	int level=0;
	while(!Q.empty()){
		queue<int> tmp;
		level++;
		if(maxSum<Q.size()){
			maxSum=Q.size();
			maxL=level;
		}
		while(!Q.empty()){
			int top=Q.front();
			Q.pop();
			for(int i=0;i<child[top].size();i++){
				tmp.push(child[top][i]);
			}
		}
		Q=tmp;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int ID,k,son;
	for(int i=0;i<m;i++){
		scanf("%d%d",&ID,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&son);
			child[ID].push_back(son);
		}
	}
	BFS();
	printf("%d %d\n",maxSum,maxL);
	return 0;
}
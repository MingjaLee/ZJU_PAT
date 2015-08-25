#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int N=100005;
struct node{
	vector<int> child;
	int sold;
}Node[N];
int n;
double p,r,ans=0;
void Create(){
	int k,t;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0)
			scanf("%d",&Node[i].sold);
		else{
			for(int j=0;j<k;j++){
				scanf("%d",&t);
				Node[i].child.push_back(t);
			}
		}
	}
}
void BFS(){
	queue<int> Q;
	Q.push(0);
	int level=0;
	while(!Q.empty()){
		queue<int> q2;
		int num=0;
		while(!Q.empty()){
			int top=Q.front();
			Q.pop();
			if(Node[top].child.size()==0)
				num+=Node[top].sold;
			else{
				for(int i=0;i<Node[top].child.size();i++){
					int child=Node[top].child[i];
					q2.push(child);
				}
			}
		}
		Q=q2;
		if(num!=0){
			ans+=num*p*pow(1+r*0.01,level);
		}
		level++;
	}
}
int main()
{
	scanf("%d%lf%lf",&n,&p,&r);
	Create();
	BFS();
	printf("%.1f\n",ans);
	return 0;
}
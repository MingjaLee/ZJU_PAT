#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int N=100005;
struct node{
	vector<int> child;
	int step;
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
	Node[0].step=0;
	Q.push(0);
	while(!Q.empty()){
		int top=Q.front();
		Q.pop();
		if(Node[top].child.size()==0){
			ans+=Node[top].sold*p*pow((1+r*0.01),Node[top].step);
		}
		else{
			for(int i=0;i<Node[top].child.size();i++){
				int child=Node[top].child[i];
				Q.push(child);
				Node[child].step=Node[top].step+1;		
			}

		}
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
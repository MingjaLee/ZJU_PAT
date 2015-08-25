#include <iostream>
#include <algorithm>
using namespace std;
const int N=101;
const int M=6000;
struct edge{
	int u,v;
	int cost,flag;
}E[M];
int father[N],n;
bool cmp(edge a,edge b){
	if(a.flag!=b.flag) return a.flag>b.flag;
	else return a.cost<b.cost;
}
int findfather(int x){
	int r=x;
	while(r!=father[r])
		r=father[r];
	while(x!=father[x]){
		father[x]=r;
		x=father[x];
	}
	return r;
}
bool Union(int a,int b){
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA==faB) return false;
	else{
		father[faB]=faA;
		return true;
	}
}
int kruskal(int n,int m){
	int ans=0,NumEdge=0;
	for(int i=1;i<=n;i++)
		father[i]=i;
	sort(E,E+m,cmp);
	for(int i=0;i<m;i++){
		if(Union(E[i].u,E[i].v)){
			if(E[i].flag==0)
				ans+=E[i].cost;
			if(++NumEdge==n-1) return ans;
		}
	}
	if(NumEdge!=n-1) return -1;
}
int main()
{
	while(scanf("%d",&n)!=EOF && n!=0){
		int m=n*(n-1)/2;
		int u,v,cost,flag;
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&E[i].u,&E[i].v,&E[i].cost,&E[i].flag);
		}
		int ans=kruskal(n,m);
		printf("%d\n",ans);
	}
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
const int N=101;
struct edge{
	int u,v;
	int cost;
}E[N];
int father[N];
int n,m;
bool cmp(edge a,edge b){
	return a.cost<b.cost;
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
int kruskal(){
	int ans=0,Numedge=0;
	for(int i=1;i<=m;i++)
		father[i]=i;
	sort(E,E+n,cmp);
	for(int i=0;i<n;i++){
		int u=E[i].u;
		int v=E[i].v;
		if(Union(u,v)){
			ans+=E[i].cost;
			if(++Numedge==m-1)
				return ans;
		}
	}
	if(Numedge!=m-1) return -1;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0) break;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);
		}
		int ans=kruskal();
		if(ans!=-1)
			printf("%d\n",ans);
		else
			printf("?\n");	
	}
	return 0;
}
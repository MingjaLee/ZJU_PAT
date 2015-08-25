#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int father[N];
bool isRoot[N];
int findFather(int x){
	int a=x;
	while(x!=father[x])
		x=father[x];
	while(a!=father[a]){
		father[a]=x;
		a=father[a];
	}
	return x;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB)
		father[faB]=faA;
}
void Init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
		isRoot[i]=false;
	}
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int a,b;
		Init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		for(int i=1;i<=n;i++)
			isRoot[findFather(i)]=true;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(isRoot[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
/*
Sameple1 Input
4 2
1 4
2 3
Sameple 1 Output
2

Sameple two Input
7 5
1 2
2 3
3 1
1 4
5 6
Sameple two Input
3
*/
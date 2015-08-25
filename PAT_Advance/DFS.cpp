#include <iostream>
using namespace std;
const int maxn=30;
int n,V,maxValue=0;
int w[maxn],c[maxn];
void DFS(int index,int sumW,int sumC){
	if(index>n) return;
	DFS(index+1,sumW,sumC);
	if(sumW+w[index]<=V){
		if(sumC+c[index]>maxValue)
			maxValue=sumC+c[index];
		DFS(index+1,sumW+w[index],sumC+c[index]);
	}
}
int main()
{
	scanf("%d%d",&n,&V);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	DFS(1,0,0);
	printf("%d\n",maxValue);
	return 0;
}
/*
Sameple Input
5 8
3 5 1 2 2
4 5 2 1 3
Sample Output
10
*/
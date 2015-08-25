#include <iostream>
#include <cstdio>

using namespace std;
const int N=105;
int num[N];
int n,m;

void PrintMove(int n,int m){
	m%=n;
	int cnt=0;
	for(int i=n-m;i<n;i++){
		if(++cnt > 1) printf(" ");;
		printf("%d", num[i]);
	}
	for(int i=0;i<n-m;i++){
		if(++cnt > 1) printf(" ");
		printf("%d", num[i]);
	}
	printf("\n");
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		PrintMove(n,m);
		PrintMove(n, m);

	}
	return 0;
}
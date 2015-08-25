#include <iostream>
#include <cstdio>

using namespace std;
const int N=105;
int HashNum[N]={0};
int main()
{
	int n;
	int x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		HashNum[x]++;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&x);
		if(i>0) printf(" ");
		printf("%d",HashNum[x]);
	}
	printf("\n");
	return 0;
}
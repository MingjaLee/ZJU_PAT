#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=105;
int num[N][N];
int dp[N];
int main()
{
	int c,n;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				scanf("%d",&num[i][j]);
				if(i==n) dp[j]=num[i][j];
			}
		}
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=i;j++)
				dp[j]=max(dp[j],dp[j+1])+num[i][j];
		}
		printf("%d\n",dp[1]);
	}
	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
const int N=20;
const int M=N*(N-1)/2;
int main()
{
	int n,dp[N+1][M+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=N;i++){
		dp[i][0]=1;
		for(int r=0;r<i;r++){
			for(int j=0;j<=M;j++){
				if(dp[r][j]==1){
					dp[i][(i-r)*r+j]=1;
				}
			}
		}
	}
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=M;i++){
			if(dp[n][i]==1){
				if(i!=0) printf(" ");
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
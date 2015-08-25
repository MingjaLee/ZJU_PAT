#include <iostream>
#include <algorithm>
using namespace std;
const int N=201;
const int LEN=10001;
int Eva[N],stripe[LEN],dp[N][LEN];
int n,m,l;
void Input(){
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&Eva[i]);
	scanf("%d",&l);
	for(int i=1;i<=l;i++)
		scanf("%d",&stripe[i]);
	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int i=0;i<=l;i++)
		dp[0][i]=0;
}
int main()
{
	Input();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=l;j++){
			if(Eva[i]==stripe[j])
				dp[i][j]=dp[i][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	printf("%d\n",dp[m][l]);
	return 0;
}
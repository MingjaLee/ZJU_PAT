#include <iostream>
#include <cstring>
using namespace std;
const int N=1005;
char str[N];
int dp[N][N];
int main()
{
	gets(str);
	int len=strlen(str),ans=1;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1 && str[i]==str[i+1]){
			dp[i][i+1]=1;
			ans=2;
		}
	}
	for(int L=3;L<=len;L++){
		for(int i=0;i+L-1<len;i++){
			int j=i+L-1;
			if(str[i]==str[j] && dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	printf("%d\n",ans);	
	return 0;
}

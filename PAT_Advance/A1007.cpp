#include <iostream>
#include <algorithm>
using namespace std;
const int N=10005;
int a[N],dp[N],k;
int main()
{
	while(scanf("%d",&k)!=EOF){
		for(int i=0;i<k;i++){
			scanf("%d",&a[i]);
		}
		dp[0]=a[0];
		for(int i=1;i<k;i++){
			dp[i]=max(a[i],dp[i-1]+a[i]);
		}
		int ed=0;
		for(int i=0;i<k;i++){
			if(dp[ed]<dp[i])
				ed=i;
		}
		if(dp[ed]<0){
			printf("%d %d %d\n",0,dp[0],dp[k-1]);
			continue;
		}
		int st=ed,sum=0;
		for(int i=ed;i>=0;i--){
			sum+=a[i];
			if(sum==dp[ed])
				st=i;
		}
		printf("%d %d %d\n",dp[ed],a[st],a[ed]);
	}
	return 0;
}
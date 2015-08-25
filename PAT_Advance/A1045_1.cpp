#include <iostream>
#include <algorithm>
using namespace std;
const int N=201;
const int LEN=10001;
int stripe[LEN],love[N],dp[LEN],prior[N]={0};
int n,m,l;
void Input(){
	scanf("%d",&n);
	scanf("%d",&m);
	int p=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&love[i]);
		prior[love[i]]=i;
	}
	scanf("%d",&l);
	for(int i=1;i<=l;i++){
		scanf("%d",&stripe[i]);
	}	
}
int main()
{
	Input();
	int ans=0;
	for(int i=1;i<=l;i++){
		if(prior[stripe[i]]==0){
			dp[i]=0;
		}
		else{
			dp[i]=1;
			for(int j=1;j<i;j++){
				if(prior[stripe[j]] <= prior[stripe[i]] && dp[j]+1>dp[i])
					dp[i]=dp[j]+1;
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
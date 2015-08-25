#include <iostream>
#include <cstring>
using namespace std;
const int maxn=25;
const int maxv=45;
const int V=40;
int w[maxn],dp[maxv],s[maxv],n;
void Init(){
	memset(dp,0,sizeof(dp));
	memset(s,0,sizeof(s));
	s[0]=1;
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
		}
		Init();
		for(int i=1;i<=n;i++){
			for(int v=V;v>=w[i];v--){
				dp[v]=max(dp[v],dp[v-w[i]]+w[i]);
				s[v]=s[v]+s[v-w[i]];
			}
		}
		printf("%d\n",s[V]);
	}
	return 0;
}
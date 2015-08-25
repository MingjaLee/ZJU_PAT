#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=10005;
const int maxv=105;
int dp[maxv],w[maxn];
bool choice[maxn][maxv],flag[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+n+1,cmp);
	memset(dp,0,sizeof(dp));
	memset(flag,0,sizeof(flag));
	memset(choice,0,sizeof(choice));
	for(int i=1;i<=n;i++){
		for(int v=m;v>=w[i];v--){
			if(dp[v]<=dp[v-w[i]]+w[i]){
				dp[v]=dp[v-w[i]]+w[i];
				choice[i][v]=true;
			}
		}
	}
	if(dp[m]!=m){
		printf("No Solution\n");
		return 0;
	}
	else{
		int k=n,v=m,num=0;
		while(k>0){
			if(choice[k][v]==true){
				num++;
				flag[k]=true;
				v-=w[k];
			}
			else flag[k]=false;
			k--;
		}
		for(int i=n;i>=1;i--){
			if(flag[i]){
				printf("%d",w[i]);
				if(--num==0) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
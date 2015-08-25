#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MOD=1000000007;
const int N=1e5+5;
const char PAT[]="PAT";
char str[N];
int dp[N];
void PrintDP(int n){
	for(int i=0;i<n;i++)
		printf("%d\t",dp[i]);
	printf("\n");
}
void PrintStr(char str[],int n){
	for(int i=0;i<n;i++)
		printf("%c\t",str[i]);
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	while(scanf("%s",str)!=EOF){
		memset(dp,0,sizeof(dp));
		int len=strlen(str);
	//	PrintStr(str,len);
		if(str[0]=='P') dp[0]=1;
		for(int i=1;i<len;i++){
			dp[i] = (str[i]=='P') ? dp[i-1]+1 : dp[i-1];
			dp[i]%=MOD;
		}
	//	PrintDP(len);
		dp[0]=0;
		for(int i=1;i<len;i++){
			if(str[i]=='A'){
				dp[i]=dp[i-1]+dp[i];
			}
			else{
				dp[i]=dp[i-1];
			}
			dp[i]%=MOD;
		}
	//	PrintDP(len);
		dp[1]=0;
		for(int i=2;i<len;i++){
			if(str[i]=='T'){
				dp[i]=dp[i-1]+dp[i];
			}
			else{
				dp[i]=dp[i-1];
			}
			dp[i]%=MOD;
		}
	//	PrintDP(len);
		printf("%d\n",dp[len-1]);
	}
	return 0;
}

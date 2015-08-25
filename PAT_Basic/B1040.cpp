#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MOD=1000000007;
const int N=1e5+5;
char str[N];
int preP[N];
int afterT[N];
int main()
{
	scanf("%s",str);
	int len=strlen(str);
	if(str[0]=='P') preP[0]=1;
	for(int i=1;i<len;i++){
		preP[i] = (str[i] == 'P') ? preP[i-1]+1 : preP[i-1];
	}
	if(str[len-1]=='T') afterT[len-1]=1;
	for(int i=len-2; i >=0 ; i--){
		afterT[i] = (str[i]=='T') ? afterT[i+1]+1 : afterT[i+1];
	}
	int Ans=0;
	for(int i=1;i<len-1;i++){
		if(str[i]=='A'){
			Ans = ( Ans + (preP[i-1] * afterT[i+1]) % MOD ) % MOD;
		}
	}
	printf("%d\n",Ans);
	return 0;
}
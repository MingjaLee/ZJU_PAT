#include <iostream>
#include <map>
#include <cstring>
using namespace std;
const int N=1e5+5;
const int mode=1000000007;
int pNum[N],tNum[N];
char str[N];
int main()
{
	scanf("%s",str);
	int len=strlen(str);	
	if(str[0]=='P') pNum[0]=1;
	for(int i=1;i<len;i++){
		if(str[i]=='P') pNum[i]=pNum[i-1]+1;
		else pNum[i]=pNum[i-1];
	}
	if(str[len-1]=='T') tNum[len-1]=1;
	for(int i=len-2;i>=0;i--){
		if(str[i]=='T') tNum[i]=tNum[i+1]+1;
		else tNum[i]=tNum[i+1];
	}
	int cnt=0;
	for(int i=1;i<len-1;i++){
		if(str[i]=='A'){
			cnt+=pNum[i-1]*tNum[i+1];
			cnt%=mode;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
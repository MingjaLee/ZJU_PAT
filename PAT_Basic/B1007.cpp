#include <iostream>
#include <cmath>
using namespace std;
const int maxn=100000;
int prime[maxn],pNum=0;
bool p[maxn]={0};
void Find_prime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			prime[pNum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				p[j]=true;
			}
		}
	}
}
int main()
{
	Find_prime();
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		for(int i=1;i<pNum && prime[i]<=n;i++){
			if(prime[i]-prime[i-1]==2)
				ans++;
		}
		printf("%d\n",ans);
	}	
	return 0;
}
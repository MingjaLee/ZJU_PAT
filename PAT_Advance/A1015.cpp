#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100000;
bool prime[maxn]={0};
void Find_prime(){
	prime[0]=prime[1]=true;
	for(int i=2;i<maxn;i++){
		if(prime[i]==false){
			for(int j=i+i;j<maxn;j+=i)
				prime[j]=true;
		}
	}
}
int Dreverse(int n,int d){
	int a[20],num=0;
	do{
		a[num++]=n%d;
		n/=d;
	}while(n!=0);
	int ans=0;
	for(int i=0;i<num;i++)
		ans=ans*d+a[i];
	return ans;
}
int main()
{
	Find_prime();
	int n,d;
	while(scanf("%d",&n)!=EOF && n>0){
		scanf("%d",&d);
		if(!prime[n] && !prime[Dreverse(n,d)])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
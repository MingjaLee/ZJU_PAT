#include <iostream>
using namespace std;
const int maxn=1000001;
int prime[maxn],pNum=0;
bool p[maxn]={0};
void Find_prime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			prime[++pNum]=i;
			for(int j=i+i;j<maxn;j+=i)
				p[j]=true;
		}
	}
}
void show_prime(int m,int n){
	int count=0;
	for(int i=m;i<=n;i++){
		printf("%d",prime[i]);
		count++;
		if(count%10!=0 && i<n)
			printf(" ");
		else
			printf("\n");
	}
}
int main()
{
	int m,n;
	Find_prime();
	while(scanf("%d%d",&m,&n)!=EOF){
		show_prime(m,n);
	}	
	return 0;
}
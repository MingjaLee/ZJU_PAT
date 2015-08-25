#include <iostream>
using namespace std;
const int N=105;
int num[N],n,m;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
void Move(int num[],int n,int start){
	int tmp=num[start];
	int now=start;
	int next=(start-m+n)%n;
	while(next!=start){
		num[now]=num[next];
		now=next;
		next=(next-m+n)%n;
	}
	num[now]=tmp;
	return;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		m%=n;
		if(m!=0){
			int d=gcd(n,m);
			for(int i=n-m;i<n-m+d;i++){
				Move(num,n,i);
			}
		}
		for(int i=0;i<n;i++){
			printf("%d",num[i]);
			if(i==n-1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
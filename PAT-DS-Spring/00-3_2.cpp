#include <iostream>
#include <cstdio>

using namespace std;
const int N=105;
int num[N];
int n,m;
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}
void MoveRight(int n,int m){
	if(m==0) return;
	int gd=gcd(n,m);
	int temp,pos,next;
	for(int i = n - m ; i < n - m + gd ; i++){
		temp=num[i];
		pos=i;
		do{
			next = (pos - m + n) % n;
			if(next != i) num[pos] = num[next];
			else{
				num[pos]=temp;
			}
			pos=next;
		}while(pos!=i);
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		m %= n;
		MoveRight(n,m);
		int cnt=0;
		for(int i=0;i<n;i++){
			printf("%d",num[i]);
			if(++cnt < n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
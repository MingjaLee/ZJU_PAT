#include <iostream>
#include <cmath>
using namespace std;
const int maxn=100005;
int prime[maxn],pnum=0;
bool p[maxn]={0};
void Find_Prime(){
	p[0]=p[1]=true;
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			prime[pnum++]=i;
			for(int j=i+i;j<maxn;j+=i)
				p[j]=true;
		}
	}
}
struct factor{
	int x,cnt;
}fac[20];
int num;
void PrimeFactor(int n){
	int sqr=(int)sqrt(n);
	num=0;
	for(int i=0;i<maxn && prime[i]<=sqr;i++){
		if(n%prime[i]==0){
			fac[num].x=prime[i];
			fac[num].cnt=0;
			while(n%prime[i]==0){
				fac[num].cnt++;
				n/=prime[i];
			}
			num++;
		}
		if(n==1) break;
	}
	if(n!=1){
		fac[num].x=n;
		fac[num++].cnt=1;
	}
}
void Print_fac(int n){
	printf("%d=",n);
	for(int i=0;i<num;i++){
		if(i>0)
			printf("*");
		if(fac[i].cnt>1)
			printf("%d^%d",fac[i].x,fac[i].cnt);
		else
			printf("%d",fac[i].x);
	}
	printf("\n");
}
int main()
{
	Find_Prime();
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==1)
			printf("1=1\n");
		else{
			PrimeFactor(n);
			Print_fac(n);
		}

		/*
		int a=(1<<31)-1;
		cout<<a<<endl;
		cout<<"1"<<endl;
		PrimeFactor(a);
		cout<<"2"<<endl;
		Print_fac(a);
		cout<<"3"<<endl;
		cout<<num<<endl;
		*/
	}
	return 0;
}
//97532468=2^2*11*17*101*1291
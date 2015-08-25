#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N=11000;
bool hashTable[N];
bool isprime(int x){
	if(x<=1) return false;
	int sqr=(int)sqrt(x*1.0);
	for(int i=2;i<=sqr;i++)
		if(x%i==0) return false;
	return true;
}
int SearchTable(int a,int Msize){
	for(int step=0;step<Msize;step++){
		int m=(a+step*step)%Msize;
		if(!hashTable[m]){
			hashTable[m]=true;
			return m;
		}
	}
	return -1;
}
int main()
{
	int n,Msize,t;
	while(scanf("%d%d",&Msize,&n)!=EOF){
		memset(hashTable,0,sizeof(hashTable));
		while(!isprime(Msize))
			Msize++;
		int index;
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			index=SearchTable(t,Msize);
			if(i!=0) printf(" ");
			if(index!=-1)
				printf("%d",index);
			else
				printf("-");
		}
		printf("\n");
	}
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
const int Max=10003;
int prime[Max];
bool isPrime(int num)
{
	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0) return false;
	return true;
}
void Init_Prime()
{
	int i,count;
	prime[1]=2;
	for(i=3,count=1;count<Max;i++)
		if(isPrime(i))
			prime[++count]=i;
}
void output(int m,int n)
{
	int i,j,k;
	k=(n-m+1)/10;
	for(j=0;j<k;j++)
	{
		int flag=0;
		for(i=0;i<10;i++)
		{
			if(flag) cout<<" ";
			else flag=1;
			cout<<prime[m++];
		}
		cout<<endl;
	}
	if(m>n) return;
	int index=0;
	while(m<=n)
	{
		if(index)
			cout<<" ";
		else
			index=1;
		cout<<prime[m++];
	}
	cout<<endl;
}
int main(int argc, char *argv[])
{
	int m,n;
	Init_Prime();
	while(cin>>m>>n)
		output(m,n);
	return 0;
}
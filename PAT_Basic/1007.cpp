#include <iostream>
#include <cmath>
using namespace std;
const int Nmax=100001;
int num[Nmax];
bool isPrime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}
int main(int argc, char *argv[])
{
	int pre_=2,current_;
	for(int i=3;i<Nmax;i++)
	{
		if(isPrime(i))
		{
			if(i-pre_==2)
				num[i]=num[i-1]+1;
			else
				num[i]=num[i-1];
			pre_=i;
		}
		else
			num[i]=num[i-1];
	}
	int n;
	while(cin>>n)
		cout<<num[n]<<endl;
	return 0;
}
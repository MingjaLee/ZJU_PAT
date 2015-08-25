#include <iostream>
using namespace std;
int ans=0;
int Callatz(int n)
{
	if(n%2==0)
		n/=2;
	else
		n=(3*n+1)/2;
	return n;
}
int main(int argc, char *argv[])
{
	int n;
	while(cin>>n)
	{
		while(n!=1)
		{
			n=Callatz(n);
			ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
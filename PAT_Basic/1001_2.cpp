#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int xi,zhi,flag=0;
	while(cin>>xi>>zhi)
	{
		if(xi*zhi)
		{
			if(flag)
				cout<<" ";
			else
				flag=1;
			cout<<xi*zhi<<" "<<zhi-1;
		}
	}
	if(!flag)
		cout<<"0 0";
	cout<<endl;
	return 0;
}
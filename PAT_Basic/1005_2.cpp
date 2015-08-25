#include <iostream>
using namespace std;
const int kmax=101;
int num[kmax];
void output()
{
	bool flag =false;
	for(int i=kmax-1;i>1;--i)
	{
		if(num[i])
		{
			if(flag)
				cout<<" ";
			else
				flag=true;
			cout<<i;		
		}

	}
	cout<<endl;
}
int main(int argc, char *argv[])
{
	int tmp,k;
	while(cin>>k)
	{
		for(int i=0;i<k;++i)
		{
			cin>>tmp;
			num[tmp]=1;
		}
		for(int i=2;i<kmax;++i)
		{
			if(num[i])
			{
				int j=i;
				while(j!=1)
				{
					if(j&1)
						j=(j*3+1)>>1;
					else
						j>>=1;
					if(j<kmax)
						num[j]=0;
				}
			}
		}
		output();
	}	
	return 0;
}
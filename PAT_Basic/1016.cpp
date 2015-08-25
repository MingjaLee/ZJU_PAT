#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A,B;
	char Da,Db;
	while(cin>>A>>Da>>B>>Db)
	{
		unsigned long long sum_a=0,sum_b=0;
		for(int i=0;i<A.size();i++)
			if(A[i]==Da)
				sum_a=sum_a*10+Da-'0';
		for(int i=0;i<B.size();i++)
			if(B[i]==Db)
				sum_b=sum_b*10+Db-'0';
		cout<<sum_a+sum_b<<endl;
	}
}
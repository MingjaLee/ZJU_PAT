#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a,b,d;
	while(cin>>a>>b>>d){
		if(d==10)
			cout<<a+b<<endl;
		else{
			int sum;
			string sum_d="";
			sum=a+b;
			while(sum){
				sum_d+=sum%d+'0';
				sum/=d;
			}
			if(sum_d=="")
				cout<<"0"<<endl;
			else{
				for(int i=sum_d.size()-1;i>=0;i--)
					cout<<sum_d[i];
				cout<<endl;
			}
		}
	}
	return 0;
}
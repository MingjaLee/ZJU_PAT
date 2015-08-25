#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
	LL a,b,c,sum;
	int t;
	while(cin>>t){
		for(int ix=1;ix<=t;ix++){
			cin>>a>>b>>c;
			bool flag;
			sum=a+b;
			if(a>0 && b>0 && sum<0)
				flag=true;
			else if(a<0 && b<0 && sum>=0)
				flag=false;
			else{
				if(sum>c) flag=true;
				else flag=false;
			}
			cout<<"Case #"<<ix<<": ";
			if(flag)
				cout<<"true"<<endl;
			else
				cout<<"false"<<endl;
		}
	}
}
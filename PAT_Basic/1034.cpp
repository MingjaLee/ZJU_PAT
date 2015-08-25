#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
	if(a<0)
		a=a*(-1);
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void put_fra(long long a,long long b)
{
	if(a==0)
		cout<<"0";
	else if(a>0){
		if(b==1)
			cout<<a;
		else{
			if(a>b)
				cout<<a/b<<" "<<a%b<<"/"<<b;
			else
				cout<<a<<"/"<<b;
		}
	}
	else{
		cout<<"(";
		if(b==1)
			cout<<a;
		else{
			if(a/b)
				cout<<a/b<<" "<<a%b*(-1)<<"/"<<b;
			else
				cout<<a<<"/"<<b;
		}
		cout<<")";
	}
}
int main()
{
	long long a1,b1,a2,b2,a3,b3;
	while(scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2)!=EOF){
		long long gcd1,gcd2,gcd3;
		gcd1=gcd(a1,b1);
		gcd2=gcd(a2,b2);
		a1/=gcd1,b1/=gcd1;
		a2/=gcd2,b2/=gcd2;
		//op+
		a3=a1*b2+a2*b1;
		b3=b1*b2;
		//cout<<a3<<" "<<b3<<endl;
		gcd3=gcd(a3,b3);
		//cout<<"gcd3="<<gcd3<<endl;
		a3/=gcd3,b3/=gcd3;
		//cout<<a3<<" "<<b3<<endl;
		put_fra(a1,b1);
		cout<<" + ";
		put_fra(a2,b2);
		cout<<" = ";
		put_fra(a3,b3);
		cout<<endl;
		//op-
		a3=a1*b2-a2*b1;
		b3=b1*b2;
		gcd3=gcd(a3,b3);
		a3/=gcd3,b3/=gcd3;
		put_fra(a1,b1);
		cout<<" - ";
		put_fra(a2,b2);
		cout<<" = ";
		put_fra(a3,b3);
		cout<<endl;
		//op*
		a3=a1*a2,b3=b1*b2;
		gcd3=gcd(a3,b3);
		a3/=gcd3,b3/=gcd3;
		put_fra(a1,b1);
		cout<<" * ";
		put_fra(a2,b2);
		cout<<" = ";
		put_fra(a3,b3);
		cout<<endl;
		//op/
		if(a2==0){
			put_fra(a1,b1);
			cout<<" / 0 = Inf"<<endl;
		}
		else{
			a3=a1*b2,b3=b1*a2;
			if(a2<0){
				a3*=-1;
				b3*=-1;
			}
			gcd3=gcd(a3,b3);
			a3/=gcd3,b3/=gcd3;
			put_fra(a1,b1);
			cout<<" / ";
			put_fra(a2,b2);
			cout<<" = ";
			put_fra(a3,b3);
			cout<<endl;
		}
	}
	return 0;
}
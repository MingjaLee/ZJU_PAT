#include <iostream>
#include <cstring>
using namespace std;
int data[10000000];
void format(int num)
{
	if(num<0){
		cout<<"-";
		num*=(-1);
	}
	int count=0;
	while(num!=0){
		data[++count]=num%10;
		num/=10;
	}
	cout<<data[count];
	for(int i=count-1;i>=1;i--){
		if(i%3==0)
			cout<<",";
		cout<<data[i];
	}
		
	cout<<endl;
}
int main()
{
	int a,b,c;
	while(cin>>a>>b){
		c=a+b;
		memset(data,0,sizeof(data));
		format(c);
	}
	return 0;
}
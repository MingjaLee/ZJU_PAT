#include<iostream>
using namespace std;
void change(int n)
{
	int bai,shi,ge;
	bai=n/100;
	shi=(n%100)/10;
	ge=n%10;
	for(int i=0;i<bai;++i)
		cout<<'B';
	for(int i=0;i<shi;i++)
		cout<<'S';
	for(int i=1;i<=ge;i++)
		cout<<i;
	cout<<endl;
}
int main()
{
	int n;
	while(cin>>n)
		change(n);
}
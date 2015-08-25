#include <iostream>
using namespace std;
void reverse_Part(int *a,int left,int right)
{
	int tmp;
	while(left<right)
	{
		tmp=a[left];
		a[left++]=a[right];
		a[right--]=tmp;
	}
}
void reverse(int *a,int n,int m)
{
	m=m%n;
	reverse_Part(a,0,n-1);
	reverse_Part(a,0,m-1);
	reverse_Part(a,m,n-1);	
}
int main(int argc, char *argv[])
{
	int n,m;
	int *a;
	while(cin>>n>>m)
	{
		a=new int[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		reverse(a,n,m);
		cout<<a[0];
		for(int i=1;i<n;i++)
			cout<<" "<<a[i];
		cout<<endl;
		delete a;
	}
	return 0;
}
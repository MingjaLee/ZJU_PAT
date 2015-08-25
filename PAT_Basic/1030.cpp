#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];
int M_index(int i,int n,long long b)
{
	for(;i<n && a[i]<=b;i++);
	return i-1;
}
int main()
{
	int n,p;
	while(cin>>n>>p){
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		long long k=0;
		int max_num=0;
		int M_i=0;
		for(int i=0;i<n && max_num<(n-i);i++){
			k=a[i]*p;
			M_i=M_index(M_i,n,k);
			if(max_num<M_i-i+1)
				max_num=M_i-i+1;
		}
		cout<<max_num<<endl;
		delete a;
	}
	return 0;
}
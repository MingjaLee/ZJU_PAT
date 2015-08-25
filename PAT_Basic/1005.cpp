#include <iostream>
#include<vector>
#include <set>
#include <cstdlib>
using namespace std;
int Callatz(int n)
{
	if(n%2==0)
		n/=2;
	else
		n=(3*n+1)/2;
	return n;
}
void Delete(set<int> &s,int n)
{
	if(s.count(n))
	{
		while(n!=1)
		{
			n=Callatz(n);
			s.erase(n);
		}
	}
}
int cmp(const void *x, const void *y)
{
	return *(int *)y-*(int *)x;
}
void sort(set<int> s)
{
	set<int>::iterator iter;
	int m=s.size();
	int b[m];
	int i=0;
	for(iter=s.begin();iter!=s.end();iter++)
	{
		b[i++]=*iter;
	}
	qsort(b,m,sizeof(b[0]),cmp);
	for(i=0;i<m-1;i++)
		cout<<b[i]<<" ";
	cout<<b[m-1]<<endl;

}
int main(int argc, char *argv[])
{
	int k;
	int *a;
	set<int> s;
	while(cin>>k)
	{
		a = new int[k];
		for(int i=0;i<k;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
		s.erase(1);
		for(int i=0;i<k;i++)
			Delete(s,a[i]);
		sort(s);
		delete a;
		s.clear();
	}
	return 0;
}
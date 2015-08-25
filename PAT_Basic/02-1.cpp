#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

typedef struct LNode{
	int Add;
	int data;
	int next;
};
int find_next(LNode *a,int index,int n)
{
	for(int i=0;i<n;i++)
		if(a[i].Add==index) return i;
	return -1;
}
bool LSort(LNode *a,int *n,int head)
{
	LNode temp;
	int len=0;
	int current=head,nextnode;
	if(n==0) return false;
	for(int i=0;i<*n;i++)
	{
		nextnode=find_next(a,current,*n);
		if(nextnode==-1) return false;
		temp=a[i],a[i]=a[nextnode],a[nextnode]=temp;
		current=a[i].next;
		len++;
		if(current==-1)
		{
			*n=len;
			return true;
		}
			
	}
	return true;
}
void Lreverse(LNode *a,int n,int k)
{
	int left,right;
	LNode temp;
	int i;
	for(int i=0;i<n/k;i++)
	{
		left=i*k,right=(i+1)*k-1;
		while(left<right)
		{
			temp=a[left],a[left++]=a[right],a[right--]=temp;
		}
	}
	for(int i=0;i<(n/k)*k;i++)
		a[i].next=a[i+1].Add;
	a[n-1].next=-1;
}
int main()
{
	int n,k,i;
	int len;
	int head;
	LNode *a;
	while(cin>>head>>n>>k)
	{
		a= new LNode[n];
		for(i=0;i<n;i++)
			cin >> a[i].Add >> a[i].data >> a[i].next;
		len=0;
		if(LSort(a,&n,head))
		{
			Lreverse(a,n,k);
			for(i=0;i<n-1;i++)
				printf("%.5d %d %.5d\n",a[i].Add,a[i].data,a[i].next);
			printf("%.5d %d -1\n",a[i].Add,a[i].data);
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int a[110],b[110],c[110];
int isInsert(int a[],int b[],int n)
{
	int index,i;
	for(i=1;i<n;i++)
		if(b[i]>b[i+1])
			break;
	index=++i;
	for(;i<=n;i++){
		if(a[i]!=b[i]){
			index=0;
			return index;
		}
	}
	return index;
}
void next_Insert(int b[],int c[],int n,int index)
{
	int i;
	int tmp=b[index];
	for(i=1;i<index;i++){
		if(b[i]<=tmp)
			c[i]=b[i];
		else
			break;
	}
	for(int j=index;j>i;j--){
		c[j]=b[j-1];
	}
	c[i]=tmp;
	for(int j=index+1;j<=n;j++)
		c[j]=b[j];
}
bool issort(int b[],int start,int end)
{
	for(int i=start;i<end;i++)
		if(b[i]>b[i+1])
			return false;
	return true;
}
int L_Merge(int b[],int n)
{
	int len=2;
	for(;len<n;len<<=1){
		int left=1,right=len;
		while(1){
			if(right>n) right=n;
			if(!issort(b,left,right))
				return len;
			if(right==n) break;
			left+=len;
			right+=len;
		}
	}
	return len;	
}
void show(int c[],int n)
{
	for(int i=1;i<=n;i++){
		if(i!=1)
			cout<<" "<<c[i];
		else
			cout<<c[i];
	}
	cout<<endl;
}
int main()
{
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		int index=isInsert(a,b,n);
	//	cout<<"index="<<index<<endl;
		if(index){
			next_Insert(b,c,n,index);
			cout<<"Insertion Sort"<<endl;
			show(c,n);
		}
		else{
			int len;
			len=L_Merge(b,n);
		//	cout<<"len="<<len<<endl;
			int left=1,right=len;
			while(1){
				if(right>n) right=n;
				sort(b+left,b+right+1);
				if(right==n) break;
				left+=len;
				right+=len;
			}
			cout<<"Merge Sort"<<endl;
			show(b,n);
		}
	}
	return 0;
}
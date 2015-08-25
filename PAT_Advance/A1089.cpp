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
bool isSame(int A[],int B[],int n){
	for(int i=1;i<=n;i++)
		if(A[i]!=B[i]) return false;
	return true;
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
void mergeSort(int a[],int b[],int n){
	bool flag=false;
	for(int step=2;step/2<=n;step*=2){
		if(isSame(a,b,n))
			flag=true;
		for(int i=1;i<=n;i+=step){
			sort(a+i,a+min(i+step,n+1));
		}
		if(flag==true)
			return;
	}
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
			mergeSort(a,b,n);
			cout<<"Merge Sort"<<endl;
			show(a,n);
		}
	}
	return 0;
}
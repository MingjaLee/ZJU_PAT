#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>

using namespace std;
const int N = 105;
int origin[N],now[N],next[N];
int n;
void PrintArray(int array[],int len){
	for(int i=1; i<=len; i++){
		if(i>1) printf(" ");
		printf("%d",array[i]);
	}
	printf("\n");
}
void CopyArray(int a[],int b[],int n){
	for(int i=1;i<=n;i++)
		a[i]=b[i];
}

bool isSame(int a[],int b[],int n){
	for(int i=1;i<=n;i++)
		if(a[i] != b[i]) return false;
	return true;
}

bool isInsert(){
	int index=2;
	while(index <= n && now[index] >= now[index-1]) index++;
	//printf("%d:%d\n",index,origin[])
	for(int i=index;i<=n;i++){
		if(origin[i] != now[i]) return false;
	}
	printf("Insertion Sort\n");
	int temp=now[index];
	int j=index;
	while(j > 1 && now[j-1] > temp){
		now[j]=now[j-1];
		j--;
	}
	now[j]=temp;
	PrintArray(now,n);
	return true;
}

void head_adjust(int array[],int i,int last){
	int child = i*2;
	while(child <= last){
		if(child+1 <= last && array[child] < array[child+1]) child++;
		if(array[i] > array[child]) break;
		else{
			swap(array[i],array[child]);
			i=child;
			child=child*2;
		}
	}
}
void head_sort(int array[],int n){
//	cout<<"in head sort"<<endl;
	for(int i=n/2;i>=1;i--){
		head_adjust(array,i,n);
	}
	bool flag=false;
	for(int i=n;i>=1;i--){
	//	PrintArray(array,n);
	//	system("pause");
		flag=isSame(array,now,n);
		swap(array[1],array[i]);
		head_adjust(array,1,i-1);
		if(flag){
			PrintArray(array,n);
			return;
		}
	}
//	cout<<"2"<<endl;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&origin[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&now[i]);
	}
	if(isInsert()){
		return 0;
	}
	else{
		printf("Heap Sort\n");
		//CopyArray(next,origin,n);
		head_sort(origin,n);
	}
	return 0;
}
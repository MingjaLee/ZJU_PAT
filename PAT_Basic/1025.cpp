#include <iostream>
using namespace std;
typedef struct node{
	int add;
	int date;
	int next;
};
node List[100010],Nnode[100010];
void reverse(int len,int k)
{
	if(k>len) return;
	int left,right;
	left=0,right=k-1;
	while(right<len){
		int l=left,r=right;
		node tmp;
		while(l<r){
			tmp=List[l];
			List[l++]=List[r];
			List[r--]=tmp;
		}
		left+=k;
		right+=k;
	}
	for(int i=0;i<len-1;i++)
		List[i].next=List[i+1].add;
	List[len-1].next=-1;
}
void output(int n)
{
	for(int i=0;i<n-1;i++){
		printf("%.5d %d %.5d\n",List[i].add,List[i].date,List[i].next);
	}
	printf("%.5d %d -1\n",List[n-1].add,List[n-1].date);
}
int main()
{
	int head,n,k;
	cin>>head>>n>>k;
	int current;
	for(int i=0;i<n;i++){
		cin>>current;
		Nnode[current].add=current;
		cin>>Nnode[current].date>>Nnode[current].next;
	}
	int len=0;
	node tmp;
	while(head!=-1){
		List[len++]=Nnode[head];
		head=Nnode[head].next;
	}
	//output(len);
//	system("PAUSE");
	reverse(len,k);
	output(len);
	return 0;
}
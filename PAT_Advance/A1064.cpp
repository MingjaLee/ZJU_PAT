#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int number[N],CBT[N];
int n,index=0;
void Inorder(int root){
	if(root>n) return;
	Inorder(root*2);
	CBT[root]=number[index++];
	Inorder(root*2+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&number[i]);
	sort(number,number+n);
	Inorder(1);
	for(int i=1;i<=n;i++){
		printf("%d",CBT[i]);
		if(i==n)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}
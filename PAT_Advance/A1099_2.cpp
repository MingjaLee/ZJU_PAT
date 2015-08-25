#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
const int N=103;
struct node
{
	int data;
	int lchild,rchild;
	/* data */
}Node[N];
int n;
int seq[N];

void InOrder(int root,int &index){
	if(root==-1) return;
	int lchild=Node[root].lchild;
	int rchild=Node[root].rchild;
	InOrder(lchild,index);
	Node[root].data=seq[index++];
	InOrder(rchild,index);
}

void BFS(int root){
	queue<int> Q;
	Q.push(root);
	int cnt=0;
	while(!Q.empty()){
		int top=Q.front();
		Q.pop();
		if(cnt++ > 0) printf(" ");
		printf("%d",Node[top].data);
		int lchild=Node[top].lchild;
		int rchild=Node[top].rchild;
		if(lchild != -1 ){
			Q.push(lchild);
		}
		if(rchild != -1){
			Q.push(rchild);
		}
	}
	printf("\n");
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int L,R;
		scanf("%d%d",&L,&R);
		Node[i].lchild=L;
		Node[i].rchild=R;
	}
	for(int i=0;i<n;i++)
		scanf("%d",&seq[i]);
	sort(seq,seq+n);
	int index=0;
	InOrder(0,index);
	BFS(0);
	return 0;
}

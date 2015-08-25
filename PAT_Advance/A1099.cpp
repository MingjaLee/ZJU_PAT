#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <queue>
#define BUG
using namespace std;
const int N=103;
struct node
{
	int data;
	node *lchild,*rchild;
	node(){
		data=-1;
		lchild=rchild=NULL;
	}
};
int seq[N];
int n;
void preOrder(node *&root,int &index){
	if(root==NULL) return;
	root->data=index++;
	int L,R;
	scanf("%d%d",&L,&R);
	if(L!=-1){
		root->lchild=new node();
	}
	if(R!=-1){
		root->rchild=new node();
	}
	preOrder(root->lchild,index);
	preOrder(root->rchild,index);
}
void inOrder(node *root,int &index){
	if(root==NULL || index > n) return;
	inOrder(root->lchild,index);
	root->data=seq[index++];
	inOrder(root->rchild,index);
}

#ifndef BUG
void showInOrder(node *root,int &cnt){
	if(root==NULL) return;
	showInOrder(root->lchild,cnt);
	if(cnt++ > 0) printf(" ");
	printf("%d",root->data);
	showInOrder(root->rchild,cnt);
}
#endif

void BFS(node *root){
	queue<node*> Q;
	Q.push(root);
	int cnt=0;
	while(!Q.empty()){
		node *top=Q.front();
		Q.pop();
		if(cnt++ > 0) printf(" ");
		printf("%d",top->data);
		if(top->lchild!=NULL)
			Q.push(top->lchild);
		if(top->rchild != NULL)
			Q.push(top->rchild);
	}
	printf("\n");
}

int main()
{
	scanf("%d",&n);
	node *root=new node();
	root->data=0;
	int index = 0;
	preOrder(root,index);
	for(int i=0;i<n;i++){
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+n);
	index=0;
	inOrder(root,index);
	
	#ifndef BUG
	index=0;
	showInOrder(root,index);
	printf("\n");
	#endif

	BFS(root);
	return 0;
}
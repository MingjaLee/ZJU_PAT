#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int v,height;
	node *lchild,*rchild;
}*root,*null;
void Init(){
	null=new node;
	null->height=0;
	root=null;
}
node* newNode(int v){
	node *t=new node;
	t->v=v;
	t->height=1;
	t->lchild=t->rchild=null;
	return t;
}
void getNewheight(node *root){
	root->height=max(root->lchild->height,root->rchild->height)+1;
}
void L(node *&root){
	node *temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	getNewheight(root);
	getNewheight(temp);
	root=temp;
}
void R(node *&root){
	node *temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	getNewheight(root);
	getNewheight(temp);
	root=temp;
}
void insert(node *&root,int v){
	if(root==null){
		root=newNode(v);
		return;
	}
	if(v<root->v){
		insert(root->lchild,v);
		getNewheight(root);
		if(root->lchild->height-root->rchild->height==2){
			int subL_R=root->lchild->lchild->height-root->lchild->rchild->height;
			if(subL_R==1)//LL 
				R(root);
			else if(subL_R==-1){//LR 
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		insert(root->rchild,v);
		getNewheight(root);
		if(root->rchild->height-root->lchild->height==2){
			int subL_R=root->rchild->lchild->height-root->rchild->rchild->height;
			if(subL_R==1){//RL
				R(root->rchild);
				L(root);
			}
			else if(subL_R==-1)//RR
				L(root);
		}
	}
}
int main()
{
	int n,v;
	Init();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d\n",root->v);
	return 0;
}
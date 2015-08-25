#include <iostream>
#include <queue>
using namespace std;
const int N=35;
struct node{
	int data;
	node *lchild,*rchild;
};
int n,post[N],inorder[N];
void get_Traversals(int array[],int n){
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);
}
node* Create(int postL,int postR,int inL,int inR){
	if(postL>postR)
		return NULL;
	node* root=new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(inorder[k]==post[postR])
			break;
	}
	int numleft=k-inL;
	root->lchild=Create(postL,postL+numleft-1,inL,k-1);
	root->rchild=Create(postL+numleft,postR-1,k+1,inR);
	return root;
}
void Level_Traveral(node *root){
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty()){
		node* tmp=Q.front();
		Q.pop();
		if(tmp!=NULL)
			printf("%d",tmp->data);
		if(tmp->lchild!=NULL)
			Q.push(tmp->lchild);
		if(tmp->rchild!=NULL)
			Q.push(tmp->rchild);
		if(!Q.empty())
			printf(" ");
		else
			printf("\n");
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		get_Traversals(post,n);
		get_Traversals(inorder,n);
		node *root=Create(0,n-1,0,n-1);;
		Level_Traveral(root);
	}
	return 0;
}
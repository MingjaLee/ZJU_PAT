#include <iostream>
using namespace std;
const int N=1005;
struct node{
	int data;
	node *lchild,*rchild;
};
int seq[N],pre[N];
int n,account,out;
void Insert(node *&root,int data){
	if(root==NULL){
		root=new node;
		root->data=data;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(data<root->data)
		Insert(root->lchild,data);
	else
		Insert(root->rchild,data);
}
node* Create(int a[],int n){
	node *root=new node;
	root->data=a[0];
	root->lchild=root->rchild=NULL;
	for(int i=1;i<n;i++)
		Insert(root,a[i]);
	return root;
}
void Preorder(node *root){
	if(root==NULL) return;
	pre[account++]=root->data;
	Preorder(root->lchild);
	Preorder(root->rchild);
}
void Post_Traveral(node *root){
	if(root==NULL) return;
	Post_Traveral(root->lchild);
	Post_Traveral(root->rchild);
	printf("%d",root->data);
	if(++out==n)
		printf("\n");
	else
		printf(" ");
}
void Miroor_Preorder(node *root){
	if(root==NULL) return;
	pre[account++]=root->data;
	Miroor_Preorder(root->rchild);
	Miroor_Preorder(root->lchild);
}
void Miroor_PostTra(node *root){
	if(root==NULL) return;
	Miroor_PostTra(root->rchild);
	Miroor_PostTra(root->lchild);
	printf("%d",root->data);
	if(++out==n)
		printf("\n");
	else
		printf(" ");
}
bool isPreorder(){
	for(int i=0;i<n;i++)
		if(seq[i]!=pre[i])
			return false;
	return true;
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&seq[i]);
		node *root=Create(seq,n);
		Preorder(root);
		account=0;
		if(isPreorder()){
			printf("YES\n");
			out=0;
			Post_Traveral(root);
		}
		else{
			account=0;
			Miroor_Preorder(root);
			if(isPreorder()){
				printf("YES\n");
				out=0;
				Miroor_PostTra(root);
			}
			else
				printf("NO\n");
		}
	}
	return 0;
}
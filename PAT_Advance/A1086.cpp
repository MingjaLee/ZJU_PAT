#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
const int maxn=70;
struct node{
	int data;
	node *lchild,*rchild;
};
int pre[maxn],inorder[maxn],n;
int postIndex;
void get_Traveral(){
	char op[5];
	int end=n<<1,data;
	int pre_i=0,in_i=0;
	stack<int> st;
	for(int i=0;i<end;i++){
		scanf("%s",op);
		if(strcmp(op,"Push")==0){
			scanf("%d",&data);
			pre[pre_i++]=data;
			st.push(data);
		}
		else{
			data=st.top();
			st.pop();
			inorder[in_i++]=data;
		}
	}
}
node* Create(int preL,int preR,int inL,int inR){
	if(preL>preR) return NULL;
	node *root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;k++)
		if(pre[preL]==inorder[k])
			break;
	int numleft=k-inL;
	root->lchild=Create(preL+1,preL+numleft,inL,k-1);
	root->rchild=Create(preL+numleft+1,preR,k+1,inR);
	return root;
}
void Post_Traveral(node *root){
	if(root==NULL) return;
	Post_Traveral(root->lchild);
	Post_Traveral(root->rchild);
	printf("%d",root->data);
	if(++postIndex==n)
		printf("\n");
	else
		printf(" ");
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		get_Traveral();
		postIndex=0;
		node *root=Create(0,n-1,0,n-1);
		Post_Traveral(root);
	}
	return 0;
}
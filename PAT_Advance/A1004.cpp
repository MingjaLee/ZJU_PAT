#include <iostream>
#include <queue>
#define N 102
using namespace std;

typedef struct node{
	int nc;
	int child[N];
};
node family[N];
void LevelTraverse(){
	node Q[N];
	node p;
	int front=-1,rear=-1,last=0;
	int leafcount=0;
	bool flag=false;
	Q[++rear]=family[1];
	while(front<rear){
		p=Q[++front];
		for(int i=0;i<p.nc;i++){
			Q[++rear]=family[p.child[i]];
		}
		if(p.nc==0) leafcount++;
		if(front==last){
			last=rear;
			if(flag)
				cout<<" ";
			else
				flag=true;
			cout<<leafcount;
			leafcount=0;
		}
	}
	cout<<endl;
}
int main()
{
	int n,m,d,k;
	while(cin>>n>>m){
		for(int i=0;i<N;i++)
			family[i].nc=0;
		for(int i=0;i<m;i++){
			cin>>d>>k;
			family[d].nc=k;
			for(int j=0;j<k;j++)
				cin>>family[d].child[j];
		}
		LevelTraverse();
	}
	return 0;
}
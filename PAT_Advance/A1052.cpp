#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=100005;
struct Node{
	bool flag;
	int addr,key,next;
}node[N];
bool cmp(Node a,Node b){
	if(a.flag==false || b.flag==false)
		return a.flag>b.flag;
	else
		return a.key<b.key;
}
void output(int account){
	if(account==0){
		printf("0 -1\n");
		return ;
	}
	printf("%d %05d\n",account,node[0].addr);
	for(int i=0;i<account;i++){
		if(i>0) printf("%05d\n",node[i].addr);
		printf("%05d %d ",node[i].addr,node[i].key);
	}
	printf("-1\n");
}
int main()
{
	int n,first;
	while(scanf("%d%d",&n,&first)!=EOF){
		int addr,key,next;
		memset(node,0,sizeof(node));
		for(int i=0;i<n;i++){
			scanf("%d",&addr);
			node[addr].addr=addr;
			scanf("%d%d",&node[addr].key,&node[addr].next);
		}
		int account=0;
		for(int p=first;p!=-1;p=node[p].next){
			node[p].flag=true;
			account++;
		}
		sort(node,node+N,cmp);
		output(account);
	}
	return 0;
}
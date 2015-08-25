#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
struct Node{
	int addr,next;
	char ch;
}node[N];
void swap(int &a,int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}
int get_length(int L){
	int len=0;
	while(L!=-1){
		len++;
		L=node[L].next;
	}
	return len;
}
int main()
{
	int L1,L2,n;
	while(scanf("%5d%5d%d",&L1,&L2,&n)!=EOF){
		memset(node,-1,sizeof(node));
		Node t;
		for(int i=0;i<n;i++){
			scanf("%5d %c %5d",&t.addr,&t.ch,&t.next);
			node[t.addr]=t;
		}
		int len1,len2;
		len1=get_length(L1);
		len2=get_length(L2);
		if(len1<len2){
			swap(len1,len2);
			swap(L1,L2);
		}
		for(int i=0;i<len1-len2;i++)
			L1=node[L1].next;
		while(L1!=-1 && L2!=-1){
			if(L1==L2) break;
			L1=node[L1].next;
			L2=node[L2].next;
		}
		if(L1==L2 && L1!=-1)
			printf("%05d\n",L1);
		else
			printf("-1\n");
	}
	return 0;
}
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
const int N = 1e5+5;
struct node{
	int addr;
	int data;
	int next;
}Node[N];
int st,n,removeSt=-1;
bool flag=false;
set<int> Same;
int getNext(int p){
	if(p==-1)
		return -1;
	else
		return Node[p].next;
}
void PrintList(int start){
	if(start==-1) return;
	printf("%05d %d ",start,Node[start].data);
	start=getNext(start);
	while(start!=-1){
		printf("%05d\n%05d %d ",start,start,Node[start].data);
		start=getNext(start);
	}
	printf("-1\n");
}
int main()
{
	scanf("%d%d",&st,&n);
	for(int i=0;i<n;i++){
		int addr;
		scanf("%d",&addr);
		scanf("%d%d",&Node[addr].data,&Node[addr].next);
		Node[addr].addr=addr;
	}
	int p=st,q=-1;
	int preP=N-1,preQ=N-1;
	while(p!=-1){
		int tmp=(int)abs(Node[p].data);
		if( Same.find(tmp)==Same.end() ){
		//	printf("In List %05d\n",p);
			Node[preP].next=p;
			preP=p;
			Same.insert(tmp);
		}
		else{
		//	printf("In remove %05d\n",p);
			if(removeSt==-1){
				removeSt=p;
				preQ=p;
			}
			else{
				Node[preQ].next=p;
				preQ=p;
			}
		}
		p=getNext(p);
	}
	Node[preP].next=-1;
	Node[preQ].next=-1;
	PrintList(st);
	PrintList(removeSt);
	return 0;
}
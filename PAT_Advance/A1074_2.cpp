#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N=100005;
struct Node{
	int addr,data,next;
}node[N];
vector<int> v;
void reverse_out(int k){
	int size=v.size(),group;
	group=size/k;
	int first=k-1,end=0;
	bool next=false;
	for(int i=0;i<group;i++){
		for(int j=first;j>=end;j--){
			if(next==true)
				printf("%05d\n",v[j]);
			else next=true;
			printf("%05d %d ",v[j],node[v[j]].data);
		}
		first+=k;
		end+=k;
	}
	if(size%k!=0){
		for(int j=group*k;j<size;j++){
			if(next==true)
				printf("%05d\n",v[j]);
			else
		 		next=true;
 			printf("%05d %d ",v[j],node[v[j]].data);
		}
	}
	printf("-1\n");
}
int main()
{
	int first,n,k;
	while(scanf("%d%d%d",&first,&n,&k)!=EOF){
		int addr;
		v.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&addr);
			node[addr].addr=addr;
			scanf("%d%d",&node[addr].data,&node[addr].next);
		}
		for(int p=first;p!=-1;p=node[p].next)
			v.push_back(p);
		reverse_out(k);
	}
	return 0;
}

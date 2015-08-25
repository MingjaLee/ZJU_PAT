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
	int account=0;
	int first=k-1,end=0;
	for(int i=0;i<group;i++){
		for(int j=first;j>=end;j--){
			printf("%05d %d ",v[j],node[v[j]].data);
			account++;
			if(account==size){
				printf("-1\n");
				return ;				
			}
			else if(j==end){
				if(first+k<size)
					printf("%05d\n",v[first+k]);
				else
					printf("%05d\n",v[first+1]);
			}
			else
				printf("%05d\n",v[j-1]);
		}
		first+=k;
		end+=k;
	}
	if(account!=size){
		for(int j=group*k;j<size;j++){
			printf("%05d %d ",v[j],node[v[j]].data);
			if(j==size-1)
				printf("-1\n");
			else
				printf("%05d\n",v[j+1]);
		}
	}
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

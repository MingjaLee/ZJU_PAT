#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int HashTable[1005];
int main()//using Hash Search
{
	int n,m,v1,v2;
	while(scanf("%d%d",&n,&m)!=EOF){
		int t;
		memset(HashTable,0,sizeof(HashTable));
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			HashTable[t]++;
		}
		bool solved=false;
		for(int i=0;i<=m;i++){
			if(HashTable[i]>0 && HashTable[m-i]>0){
				if(i==m-i && HashTable[i]<2)
					continue;
				printf("%d %d\n",i,m-i);
				solved=true;
				break;
			}
		}
		if(!solved)
			printf("No Solution\n");
	}
	return 0;
}
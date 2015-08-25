#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
int HashTable[N];
int bets[N];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(HashTable,0,sizeof(HashTable));
		for(int i=0;i<n;i++){
			scanf("%d",&bets[i]);
			if(HashTable[bets[i]]<2)
				HashTable[bets[i]]++;
		}
		int i;
		/*
		for(int j=0;j<n;j++){
			printf("%d %d\n",bets[j],HashTable[bets[j]]);
		}
		*/
		for(i=0;i<n;i++){
			if(HashTable[bets[i]]==1){
				printf("%d\n",bets[i]);
				break;
			}
		}
		if(i==n)
			printf("None\n");
	}
	return 0;
}
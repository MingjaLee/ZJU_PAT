#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int coins[N];
int main()//using Tow points
{
	int n,m,v1,v2;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&coins[i]);
		sort(coins,coins+n);
		int i=0,j=n-1;
		bool solved=false;
		while(i<j){
			if(coins[i]+coins[j]==m){
				solved=true;
				break;
			}
			else if(coins[i]+coins[j]<m){
				i++;
			}
			else
				j--;
		}
		if(solved)
			printf("%d %d\n",coins[i],coins[j]);
		else
			printf("No Solution\n");
	}	
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int coins[N];
int search_pair(int left,int right,int x){
	if(x<=0) return -1;
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(coins[mid]==x)
			return mid;
		else if(coins[mid]<x)
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}
int main()//using Binary Search
{
	int n,m,v1,v2;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&coins[i]);
		sort(coins,coins+n);
		int v1=-1,v2=-1;
		for(int i=0;i<n;i++){
			int t=search_pair(i+1,n-1,m-coins[i]);
			if(t!=-1){
				v1=coins[i];
				v2=coins[t];
				break;
			}
		}
		if(v1!=-1)
			printf("%d %d\n",v1,v2);
		else
			printf("No Solution\n");
	}
	return 0;
}
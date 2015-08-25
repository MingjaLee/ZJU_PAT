#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
struct node
{
	int G;
	int S;
	int K;
	/* data */
};
node sub(node a,node b){
	node ret;
	int borrow=0;
	ret.K=a.K-b.K;
	if(ret.K<0){
		ret.K+=29;
		a.S--;
	}
	ret.S=a.S-b.S;
	if(ret.S<0){
		ret.S+=17;
		a.G--;
	}
	ret.G=a.G-b.G;
	return ret;
}
void showNode(node a){
	printf("%d.%d.%d\n",a.G,a.S,a.K);
}
int main()
{
	node need,pay;
	node rest;
	while(scanf("%d.%d.%d %d.%d.%d",&need.G,&need.S,&need.K,&pay.G,&pay.S,&pay.K)!=EOF){
		rest=sub(pay,need);
		if(rest.G<0){
			rest=sub(need,pay);
			rest.G=-rest.G;
		}
		showNode(rest);
	}
	return 0;
}
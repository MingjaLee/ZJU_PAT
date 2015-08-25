#include <iostream>
#include <algorithm>
using namespace std;
struct mooncake{
	double store;
	double sell;
	double price;
}m[1005];
bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
}
int main()
{
	int n;
	double D;
	while(scanf("%d%lf",&n,&D)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lf",&m[i].store);
		for(int i=0;i<n;i++){
			scanf("%lf",&m[i].sell);
			m[i].price=m[i].sell/m[i].store;
		}
		sort(m,m+n,cmp);
		double max_profit=0;
		for(int i=0;i<n && D>0;i++){
			if(D>=m[i].store){
				max_profit+=m[i].sell;
				D-=m[i].store;
			}
			else{
				max_profit+=m[i].price*D;
				D=0;
			}
		}
		printf("%.2f\n",max_profit);
	}
	return 0;
}
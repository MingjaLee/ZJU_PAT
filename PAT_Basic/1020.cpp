#include <iostream>
#include <algorithm>
using namespace std;
typedef struct moomcate{
	float amount;
	float cost;
	float price;
};
void input(moomcate *m,int n)
{
	for(int i=0;i<n;i++)
		cin>>m[i].amount;
	for(int i=0;i<n;i++){
		cin>>m[i].cost;
		m[i].price=m[i].cost*(1.0)/m[i].amount;
	}
}
bool cmp(moomcate x,moomcate y)
{
	if(x.price>y.price)
		return true;
	else 
		return false;
}
int main()
{
	int n,d;
	moomcate *m;
	double profit;
	while(cin>>n>>d){
		profit=0;
		m=new moomcate[n];
		input(m,n);
		sort(m,m+n,cmp);
		int i=0;
		while(d!=0 && i!=n){
			if(d>=m[i].amount){
				profit+=m[i].cost;
				d-=m[i].amount;
			}
			else{
				profit+=d*m[i].price;
				d=0;
			}
			i++;
		}
		printf("%.2f\n",profit);
	}
	return 0;
}
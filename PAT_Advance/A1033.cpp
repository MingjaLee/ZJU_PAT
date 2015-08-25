#include <iostream>
#include <algorithm>
using namespace std;
struct station{
	double price;
	double dis;
}sta[501];
double Cmax,D,Davg;
int n;
const int INF=10000000;
bool cmp(station a,station b){
	return a.dis<b.dis;
}
void output(){
	if(sta[0].dis!=0){
		printf("The maximum travel distance = 0.00\n");
		return;
	}
	int cur=0;
	double cost=0,rest_gas=0;
	while(cur<n){
		int index=-1;
		double reached=sta[cur].dis+Cmax*Davg;
		double min_price=INF;
		for(int i=cur+1;i<=n && sta[i].dis<=reached;i++){
			if(sta[i].price<min_price){
				min_price=sta[i].price;
				index=i;
				if(min_price<sta[cur].price)
					break;
			}
		}
		if(index==-1) break;
		double need_gas=(sta[index].dis-sta[cur].dis)/Davg;
		if(min_price<sta[cur].price){
			if(need_gas>=rest_gas){
				cost+=(need_gas-rest_gas)*sta[cur].price;
				rest_gas=0;
			}
			else{
				rest_gas-=need_gas;
			}
		}
		else{
			cost+=(Cmax-rest_gas)*sta[cur].price;
			rest_gas=Cmax-need_gas;
		}
		cur=index;
	}//while(cur<n)
	//cout<<"cost="<<cost<<endl;
	if(cur==n){
		printf("%.2f\n",cost);
	}
	else{
		printf("The maximum travel distance = %.2f\n",sta[cur].dis+Cmax*Davg);
	}
}
int main()
{
	while(scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&sta[i].price,&sta[i].dis);
		sta[n].price=0,sta[n].dis=D;
		sort(sta,sta+n,cmp);
	//	cout<<"before output()"<<endl;
		output();
	//	cout<<"after output()"<<endl;
	}
	return 0;
}
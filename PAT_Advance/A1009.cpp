#include <iostream>
using namespace std;
typedef struct Poly{
	int exp;
	double coe;
};
Poly poly[1001];
double ans[2001]={0.0};
int main()
{
	int n,m;
	int exp;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>poly[i].exp>>poly[i].coe;
	cin>>m;
	int exp2;
	double coe2;
	for(int i=0;i<m;i++){
		cin>>exp2>>coe2;
		for(int j=0;j<n;j++){
			ans[poly[j].exp+exp2]+=coe2*poly[j].coe;
		}
	}
	int number=0;
	for(int i=0;i<=2000;i++)
		if(ans[i]!=0.0)
			number++;
	cout<<number;
	for(int i=2000;i>=0;i--){
		if(ans[i]!=0.0)
			printf(" %d %.1lf",i,ans[i]);
	}
	cout<<endl;
	return 0;
}
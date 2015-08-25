#include <iostream>
using namespace std;
int main()
{
	char result[3]={
		'W','T','L'
	};
	int buy[3];
	double ans=1.0;
	double tmp;
	for(int i=0;i<3;i++){
		double max=0.0;
		for(int j=0;j<3;j++){
			cin>>tmp;
			if(max<tmp){
				max=tmp;
				buy[i]=j;
			}
		}
		ans*=max;
	}
	for(int i=0;i<3;i++)
		printf("%c ",result[buy[i]]);
	//cout<<(ans*0.65-1)*2<<endl;;
	//(ans*100+0.5)
	printf("%.2f\n",(ans*0.65-1)*2);
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int G1,S1,K1,G2,S2,K2;
	int g,s,k;
	while(scanf("%d.%d.%d",&G1,&S1,&K1)!=EOF){
		scanf("%d.%d.%d",&G2,&S2,&K2);
		int reg=0;
		k=(K1+K2+reg)%29;
		reg=(K1+K2+reg)/29;
		s=(S1+S2+reg)%17;
		reg=(S1+S2+reg)/17;
		g=G1+G2+reg;
		printf("%d.%d.%d\n",g,s,k);
	}
	return 0;
}
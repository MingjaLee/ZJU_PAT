#include <iostream>
#define CLK_ 100
using namespace std;
int main()
{
	int c1,c2;
	float time;
	while(cin>>c1>>c2){
		time=(float)(c2-c1)/CLK_;
		int n;
		n=(int)(time+0.5);
		int h,m,s;
		s=n%60;
		n/=60;
		m=n%60;
		n/=60;
		h=n;
		printf("%.2d:%.2d:%.2d\n",h,m,s);
	}
	return 0;
}
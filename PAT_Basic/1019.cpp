#include <iostream>
#include <cstdlib>
using namespace std;
int cmp(const void *x,const void *y)
{
	return *(int *)x-*(int *)y;
}
void to_max_min(const int &n,int &max,int &min)
{
	int num[4];
	num[0]=n/1000;
	num[1]=(n%1000)/100;
	num[2]=(n%100)/10;
	num[3]=n%10;
	qsort(num,4,sizeof(int),cmp);
	max=min=0;
	for(int i=0;i<4;i++)
	{
		max=max*10+num[3-i];
		min=min*10+num[i];
	}	
}
int main()
{
	int n,max,min;
	while(cin>>n)
	{
		to_max_min(n,max,min);
		if(max==min)
			printf("%.4d - %.4d = 0000\n",max,min);
		else{
			n=max-min;
			printf("%.4d - %.4d = %.4d\n",max,min,n);
			to_max_min(n,max,min);
			while(n!=6174){
				n=max-min;
				printf("%.4d - %.4d = %.4d\n",max,min,n);
				to_max_min(n,max,min);
			}
		}
	}
	return 0;
}
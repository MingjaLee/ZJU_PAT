#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[4];
void to_array(int x){
	memset(num,0,sizeof(num));
	int i=0;
	while(x!=0){
		num[i++]=x%10;
		x/=10;
	};
	sort(num,num+4);
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int min,max;
		do{
			to_array(n);
			min=0,max=0;
			for(int i=0;i<4;i++){
				min=min*10+num[i];
				max=max*10+num[3-i];
			}
			n=max-min;
			printf("%04d - %04d = %04d\n",max,min,n);
		}while(n!=0 && n!=6174);
	}
	return 0;
}
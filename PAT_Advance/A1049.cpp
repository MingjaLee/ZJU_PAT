#include <iostream>
using namespace std;
int main()
{
	int n,ans,a,left,now,right;
	while(scanf("%d",&n)!=EOF){
		ans=0;
		a=1;
		while(n/a!=0){
			now=n/a%10;
			left=n/(a*10);
			right=n%a;
			if(now==0)
				ans+=left*a;
			else if(now==1)
				ans+=left*a+1+right;
			else
				ans+=(left+1)*a;
			a*=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}
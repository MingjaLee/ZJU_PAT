#include <iostream>
using namespace std;
int main()
{
	int a[1000],n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[0]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]>0){
				ans+=(a[i]-a[i-1])*6+5;
			}
			else{
				ans+=(a[i-1]-a[i])*4+5;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
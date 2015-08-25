#include <iostream>
using namespace std;
const int N=100005;
int near_m=100000005;
int sum[N];
int upper_bound(int left,int right,int x){
	int mid;
	while(left<right){
		mid=(left+right)/2;
		if(sum[mid]>x){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&sum[i]);
			sum[i]+=sum[i-1];
		}
	//	cout<<"1"<<endl;
		for(int i=1;i<=n;i++){
			int j=upper_bound(i,n+1,sum[i-1]+m);
			if(sum[j-1]-sum[i-1]==m){
				near_m=m;
				break;
			}
			else if(j<=n&& sum[j]-sum[i-1]<near_m){
				near_m=sum[j]-sum[i-1];
			}
		}
	//	cout<<"2"<<endl;
		for(int i=1;i<=n;i++){
			int j=upper_bound(i,n+1,sum[i-1]+near_m);
			if(sum[j-1]-sum[i-1]==near_m)
				printf("%d-%d\n",i,j-1);
		}
	}
	return 0;
}
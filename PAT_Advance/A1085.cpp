#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int num[N];
int Myupper_bound(int left,int right,long long x){
	if(num[right-1]<=x) return right;
	int mid;
	while(left<right){
		mid=(left+right)/2;
		if(num[mid]>x)
			right=mid;
		else
			left=mid+1;
	}
	return left;
}
int main(){
	int p,n;
	while(scanf("%d%d",&n,&p)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		int ans=1;
		for(int i=0;i<n;i++){
			int j=Myupper_bound(i+1,n,(long long)num[i]*p);
			if(ans<j-i) ans=j-i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
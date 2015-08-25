#include <iostream>
#include <algorithm>
using namespace std;
const int N=100005;
int num[N];
int main()
{
	int n,p;
	while(scanf("%d%d",&n,&p)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		int ans=1;
		int i=0,j=0;
		while(i<n && j<n){
			while(j<n && num[j]<=(long long)num[i]*p){
				if(j-i+1>ans) ans=j-i+1;
				j++;
			}
			i++;
			if(n-i+1<ans) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
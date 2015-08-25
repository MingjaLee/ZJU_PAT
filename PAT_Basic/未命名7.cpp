#include <iostream>
#include <algorithm>
using namespace std;
const int N=5000+5;
struct node{
	int l,w;
}Node[N];
int dp[N];
bool cmp(node a,node b){
	if(a.l!=b.l) return a.l<b.l;
	else return a.w<b.w;
}
int main()
{
	freopen("in.txt","r",stdin);
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&Node[i].l,&Node[i].w);
		sort(Node+1,Node+1+n,cmp);
		#ifndef DE
		cout<<"-----------"<<endl;
		for(int i=1;i<=n;i++)
			cout<<Node[i].l<<" "<<Node[i].w<<endl;
		cout<<endl;
		system("pause");
		#endif
		int ans=0;
		for(int i=1;i<=n;i++){
			dp[i]=1;
			for(int j=1;j<i;j++){
				if(Node[j].l<=Node[i].l && Node[j].w<=Node[i].w){
					dp[i]=0;
					break;
				}
			}
			ans+=dp[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
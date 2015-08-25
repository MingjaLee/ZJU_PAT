#include <iostream>
#include <set>
using namespace std;
const int maxn=52;
set<int> s[maxn];
int main()
{
	int n,m,t;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&m);
			for(int j=0;j<m;j++){
				scanf("%d",&t);
				s[i].insert(t);
			}
		}
		int k,s1,s2;
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%d%d",&s1,&s2);
			int sameNum=0,totleNum=0;
			set<int>::iterator it;
			for(it=s[s1].begin();it!=s[s1].end();it++){
				if(s[s2].count((*it))==1)
					sameNum++;
			}
			totleNum=s[s1].size()+s[s2].size()-sameNum;
			printf("%.1f%%\n",sameNum*100.0/totleNum);
			
		}		
	}
	return 0;
}
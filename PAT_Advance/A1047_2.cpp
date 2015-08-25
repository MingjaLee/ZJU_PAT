#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=40010;
const int maxc=2510;
char name[maxn][5];
vector<int> course[maxc];
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main()
{
	int n,k,cNum,cID;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%s%d",name[i],&cNum);
			for(int j=0;j<cNum;j++){
				scanf("%d",&cID);
				course[cID].push_back(i);
			}
		}
		for(int i=1;i<=k;i++){
			printf("%d %d\n",i,course[i].size());
			sort(course[i].begin(),course[i].end(),cmp);
			for(int j=0;j<course[i].size();j++)
				printf("%s\n",name[course[i][j]]);
		}
	}	
	return 0;
}
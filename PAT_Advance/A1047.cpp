#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int M=2502;
const int N=26*26*26*10+2;
char name[N][5];
vector<int> course[M];
int getID(char str[]){
	int id=0;
	for(int i=0;i<3;i++)
		id=id*26+(str[i]-'A');
	id=id*10+(str[3]-'0');
	return id;
}
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		char str[5];
		int cNum,cID;
		while(n--){
			scanf("%s%d",str,&cNum);
			int id=getID(str);
			strcpy(name[id],str);
			while(cNum--){
				scanf("%d",&cID);
				course[cID].push_back(id);
			}
		}
		for(int i=1;i<=k;i++)
			sort(course[i].begin(),course[i].end());
		for(int i=1;i<=k;i++){
			int size=course[i].size();
			printf("%d %d\n",i,size);
			for(int j=0;j<size;j++){
				printf("%s\n",name[course[i][j]]);
			}
		}
		memset(course,0,sizeof(course));
	}
	return 0;
}
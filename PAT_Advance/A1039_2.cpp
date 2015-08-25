#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int M=26*26*26*10+1;
vector<int> stu_course[M];
int get_ID(char str[]){
	int index=0;
	for(int i=0;i<3;i++)
		index=index*26+(str[i]-'A');
	index=index*10+(str[3]-'0');
	return index;
}
int main()
{
	int n,m;
	char str[5];
	while(scanf("%d%d",&n,&m)!=EOF){

		for(int j=0;j<m;j++){
			int course,cNum;
			scanf("%d%d",&course,&cNum);
			for(int i=0;i<cNum;i++){
				scanf("%s",str);
				int index=get_ID(str);
				stu_course[index].push_back(course);				
			}
		}
		for(int i=0;i<n;i++){
			scanf("%s",str);
			int index=get_ID(str);
			int size=stu_course[index].size();
			sort(stu_course[index].begin(),stu_course[index].end());
			printf("%s %d",str,size);
			for(int j=0;j<size;j++)
				printf(" %d",stu_course[index][j]);
			printf("\n");
		}
		stu_course[M].clear();
	}
	return 0;
}
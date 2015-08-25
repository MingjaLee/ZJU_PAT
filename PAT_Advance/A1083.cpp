#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct student{
	char name[20],ID[20];
	int grade;
};
int n,L,H;
vector<student> stu;
bool cmp(student a,student b){
	return a.grade>b.grade;
}
int main()
{
	scanf("%d",&n);
	student tmp;
	for(int i=0;i<n;i++){
		scanf("%s%s%d",tmp.name,tmp.ID,&tmp.grade);
		stu.push_back(tmp);
	}
	scanf("%d%d",&L,&H);
	sort(stu.begin(),stu.end(),cmp);
	int left=-1,right=-1;
	int k=0;
	while(k<stu.size() && stu[k].grade>H) k++;
	left=k;
	while(k<stu.size() && stu[k].grade>=L) k++;
	right=k-1;
	if(left>right)
		printf("NONE\n");
	else{
		for(int j=left;j<=right;j++)
			printf("%s %s\n",stu[j].name,stu[j].ID);
	}
	return 0;
}
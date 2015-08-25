#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node{
	int ID;
	char name[9];
	int grade;
};
int c;
bool cmp(node a,node b){
	if(c==1)
		return a.ID<b.ID;
	else if(c==2){
		int s=strcmp(a.name,b.name);
		if(s!=0) return s<0;
		else return a.ID<b.ID;
	}
	else{
		if(a.grade!=b.grade) return a.grade<b.grade;
		else return a.ID<b.ID;
	}
}
int main()
{
	int n;
	vector<node> stu;
	node tmp;
	while(scanf("%d%d",&n,&c)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d %s %d",&tmp.ID,tmp.name,&tmp.grade);
			stu.push_back(tmp);
		}			
		sort(stu.begin(),stu.end(),cmp);
		vector<node>::iterator iter;
		for(iter=stu.begin();iter!=stu.end();iter++){
			printf("%06d %s %d\n",iter->ID,iter->name,iter->grade);
		}
		stu.clear();
	}
	return 0;
}
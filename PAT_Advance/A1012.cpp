#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef struct Student{
	int ID;
	int grade[4];
};
Student stu[2010];
char course[4]={'A','C','M','E'};
int Rank[1000000][4]={0};
int flag;
bool cmp(Student a,Student b){
	return a.grade[flag]>b.grade[flag];
}
int main()
{
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			cin>>stu[i].ID>>stu[i].grade[1]>>stu[i].grade[2]>>stu[i].grade[3];
			stu[i].grade[0]=(stu[i].grade[3]+stu[i].grade[1]+stu[i].grade[2])/3;
		}
		memset(Rank,0,sizeof(Rank));
		for(flag=0;flag<4;flag++){
			sort(stu,stu+n,cmp);
			Rank[stu[0].ID][flag]=1;
			for(int j=1;j<n;j++){
				if(stu[j].grade[flag]==stu[j-1].grade[flag])
					Rank[stu[j].ID][flag]=Rank[stu[j-1].ID][flag];
				else
					Rank[stu[j].ID][flag]=j+1;
			}
		}
		int t;	//test id
		for(int i=0;i<m;i++){
			cin>>t;
			if(Rank[t][0]==0)
				cout<<"N/A"<<endl;
			else{
				int index,best=n+1;
				for(int j=0;j<4;j++){
					if(best>Rank[t][j]){
						index=j;
						best=Rank[t][j];
					}
				}
				cout<<best<<" "<<course[index]<<endl;
			}
		}
	}
	return 0;
}
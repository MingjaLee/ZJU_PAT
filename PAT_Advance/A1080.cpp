#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int Nmax=40010;
struct student{
	int ID;
	int GE,GI;
	int sum;
	int chose[5];
	int Rank;
}stu[Nmax];
struct school{
	int number;
	int ad[Nmax];
	int quota;
}sch[100];
int n,m,k;
void input(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&sch[i].quota);
		sch[i].number=0;		
	}

	for(int i=0;i<n;i++){
		scanf("%d%d",&stu[i].GE,&stu[i].GI);
		stu[i].ID=i;
		stu[i].sum=stu[i].GE+stu[i].GI;
		for(int j=0;j<k;j++)
			scanf("%d",&stu[i].chose[j]);
	}
}
bool cmp(student a,student b){
	if(a.sum!=b.sum) return a.sum>b.sum;
	else return a.GE>b.GE;
}
void get_rank(){
	int r=0;
	for(int i=0;i<n;i++){
		if(i>0 && !(stu[i].sum==stu[i-1].sum && stu[i].GE==stu[i-1].GE) )
			r=i;
		stu[i].Rank=r;
	}
}
void admit(){
	int need=0;
	for(int i=0;i<m;i++)
		need+=sch[i].quota;
	bool out=false;
	int tmp_chose,pre_chose=-1;// mark same rank and same school
	for(int i=0;i<n;i++){
		if(need<=0 && out)
			return;
		for(int j=0;j<k;j++){//
			tmp_chose=stu[i].chose[j];
			if(sch[tmp_chose].quota>0){
				sch[tmp_chose].ad[sch[tmp_chose].number++]=stu[i].ID;
				sch[tmp_chose].quota--;
				need--;
				break;
			}
			else{
				if(i>0 && stu[i].Rank==stu[i-1].Rank && tmp_chose==pre_chose){
					sch[tmp_chose].ad[sch[tmp_chose].number++]=stu[i].ID;
					need--;
					break;
				}
			}		
		}
		pre_chose=tmp_chose;
		if(need<=0 && i>0 && stu[i].Rank!=stu[i-1].Rank)
			out =true;
	}
}
void output(){
	for(int i=0;i<m;i++)
		if(sch[i].number!=0){
			sort(sch[i].ad,sch[i].ad+sch[i].number);
		}
	for(int i=0;i<m;i++){
		if(sch[i].number==0)
			printf("\n");
		else{
			for(int j=0;j<sch[i].number;j++){
				if(j>0) printf(" ");
				printf("%d",sch[i].ad[j]);
			}
			printf("\n");
		}
	}
}
int main()
{
	input();
	sort(stu,stu+n,cmp);
	get_rank();
	admit();
	output();
	return 0;
}
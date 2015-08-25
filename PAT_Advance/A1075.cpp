#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int Nmax=10010;
struct Student{
	int ID;
	int score[6];
	bool visit;
	int all_score;
	int solve;
}stu[Nmax];
int ps[6];
int n,k,m;
void Init(){
	for(int i=1;i<=n;i++){
		stu[i].ID=i;
		stu[i].all_score=0;
		stu[i].solve=0;
		stu[i].visit=false;
		memset(stu[i].score,-1,sizeof(stu[i].score));
	}
}
bool cmp(Student a,Student b){
	if(a.all_score!=b.all_score) return a.all_score>b.all_score;
	else if(a.solve!=b.solve) return a.solve>b.solve;
	else return a.ID<b.ID;
}
void output(){
	int Rank=1;
	for(int i=1;i<=n && stu[i].visit==true;i++){
		if(i>1 && stu[i].all_score!=stu[i-1].all_score)
			Rank=i;
		printf("%d %05d %d",Rank,stu[i].ID,stu[i].all_score);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]==-1)
				printf(" -");
			else
				printf(" %d",stu[i].score[j]);
		}
		printf("\n");
	}//
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	Init();
	for(int i=1;i<=k;i++)
		scanf("%d",&ps[i]);
	int u_id,p_id,p_s;
	for(int i=0;i<m;i++){
		scanf("%5d%d%d",&u_id,&p_id,&p_s);
		if(p_s!=-1)
			stu[u_id].visit=true;
		if(p_s==-1 && stu[u_id].score[p_id]==-1)
			stu[u_id].score[p_id]=0;
		/*
		if(stu[u_id].score[p_id]<p_s){
			stu[u_id].score[p_id]=p_s;
			if(p_s==ps[p_id])
				stu[u_id].solve++;
		}
		*/
		if(p_s==ps[p_id] && stu[u_id].score[p_id] < p_s)
			stu[u_id].solve++;
		if(p_s>stu[u_id].score[p_id])
			stu[u_id].score[p_id]=p_s;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			if(stu[i].score[j]!=-1)
				stu[i].all_score+=stu[i].score[j];
	}
	sort(stu+1,stu+n+1,cmp);
	output();
	return 0;
}

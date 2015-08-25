#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define NDEBUG
using namespace std;
typedef struct Record{
	char name[25];
	int month,day,hour,minute;
	bool line;
};
Record rec[1010];
int rate[24];
bool cmp(Record x,Record y){
	int s=strcmp(x.name,y.name);
	if(s!=0) return s<0;
	else if(x.month!=y.month) return x.month<y.month;
	else if(x.day!=y.day) return x.day<y.day;
	else if(x.hour!=y.hour) return x.hour<y.hour;
	else return x.minute<y.minute;
}
void account_bill(int on,int off,int &time,int &bill){
	Record tmp=rec[on];
	while(tmp.day<rec[off].day || tmp.hour<rec[off].hour || tmp.minute<rec[off].minute){
		time++;
		bill+=rate[tmp.hour];
		if(++tmp.minute>=60){
			tmp.hour++;
			tmp.minute=0;
		}
		if(tmp.hour>=60){
			tmp.hour=0;
			tmp.day++;
		}
	}
}
void output(Record rec[],int n){
	int on=0,off,next;
	while(on<n){
		int isPrint=0;
		next=on;// next: the beginning of next user
		while(next<n && strcmp(rec[next].name,rec[on].name)==0){
			if(isPrint==0 && rec[next].line==true)
				isPrint=1;
			else if(isPrint==1 && rec[next].line==false)
				isPrint=2;
			next++;
		}//while, find next user and one user to validly Print
	//	cout<<"test0"<<endl;
		if(isPrint<2){
			on=next;
			continue;
		}
	//	cout<<"test1"<<endl;
		int Allbill=0;
		printf("%s ",rec[on].name);
		printf("%02d\n",rec[on].month);
		while(on<next){	//find all pair line of the user
			while(on<next-1 && !(rec[on].line && !rec[on+1].line))
				on++;
			off=on+1;
			if(off==next){
				on=next;
				break;
			}
			printf("%02d:%02d:%02d ",rec[on].day,rec[on].hour,rec[on].minute);
			printf("%02d:%02d:%02d ",rec[off].day,rec[off].hour,rec[off].minute);
			int time=0,bill=0;
			account_bill(on,off,time,bill);
			Allbill+=bill;
			printf("%d $%.2f\n",time,bill/100.0);
			on=off+1;
		}//while
		printf("Total amount: $%.2f\n",Allbill/100.0);
	}
}
int main()
{
	for(int i=0;i<24;i++)
		scanf("%d",&rate[i]);
	int n;
	Record tmp;
	char line_of[10];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",rec[i].name);
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].day,&rec[i].hour,&rec[i].minute);
		scanf("%s",line_of);
		if(strcmp(line_of,"on-line")==0) rec[i].line=true;
		else rec[i].line=false;
	}		
	sort(rec,rec+n,cmp);
	output(rec,n);
	return 0;
}
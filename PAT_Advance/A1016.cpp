#include <iostream>
#include <string>
#include <algorithm>
#define NDEBUG
using namespace std;
typedef struct Record{
	string name;
	int month,day,hour,minute;
	bool line;
};
Record rec[1010];
int rate[24];
bool cmp(Record x,Record y){
	if(x.name!=y.name) return x.name<y.name;
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
		if(tmp.hour>=24){
			tmp.hour=0;
			tmp.day++;
		}
	}
}
void output(Record rec[],int n){
	int on=0,off,next;
	while(on<n){
		bool isPrint=false;
		next=on;// next: the beginning of next user
		while(next<n && rec[next].name==rec[on].name){
			if(!isPrint && rec[next].line && next+1<n && !rec[next+1].line 
				&& rec[next].name==rec[next+1].name)
				isPrint=true;
			next++;
		}//while, find next user and one user to validly Print
		if(!isPrint){
			on=next;
			continue;
		}
		int Allbill=0;
		cout<<rec[on].name<<" ";
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
		cin>>rate[i];
	int n;
	Record tmp;
	string line_of;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>rec[i].name;
		scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].day,&rec[i].hour,&rec[i].minute);
		cin>>line_of;
		if(line_of=="on-line") rec[i].line=true;
		else rec[i].line=false;
	}		
	sort(rec,rec+n,cmp);
	output(rec,n);
	return 0;
}
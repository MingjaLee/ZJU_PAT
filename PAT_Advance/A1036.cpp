#include <iostream>
using namespace std;
struct student{
	char name[11];
	char sex;
	char course[20];
	int grade;
}tmp,Hfemale,Lmale;
char sex[2]={
	'M','F'
};
int main()
{
	int n;
	while(cin>>n){
		int highest=-1,lowest=101;
		while(n--){
			scanf("%s %c %s %d",tmp.name,&tmp.sex,tmp.course,&tmp.grade);
			if(tmp.sex==sex[0] && lowest>tmp.grade){
				lowest=tmp.grade;
				Lmale=tmp;
			}
			if(tmp.sex==sex[1] && highest<tmp.grade){
				highest=tmp.grade;
				Hfemale=tmp;
			}
		}
		bool flag=true;
		if(highest==-1){
			cout<<"Absent"<<endl;
			flag=false;
		}
		else
			cout<<Hfemale.name<<" "<<Hfemale.course<<endl;
		if(lowest==101){
			cout<<"Absent"<<endl;
			flag=false;
		}
		else
			cout<<Lmale.name<<" "<<Lmale.course<<endl;
		if(flag)
			cout<<Hfemale.grade-Lmale.grade<<endl;
		else
			cout<<"NA"<<endl;
	}
	return 0;
}
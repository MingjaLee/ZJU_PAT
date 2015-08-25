#include <iostream>
#include <cstdio>
#define JUDGE
using namespace std;
typedef struct Student{
	string name;
	string sno;
	int grade;
};
int main(int argc, char *argv[])
{
	#ifndef JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	Student *s;
	int max,min;
	int i_max,i_min;
	while(cin>>n)
	{
		i_max=i_min=0;
		max=0,min=100;
		s=new Student[n];
		for(int i=0;i<n;i++)
		{
			cin>>s[i].name>>s[i].sno>>s[i].grade;
			if(max<s[i].grade)
			{
				max=s[i].grade;
				i_max=i;
			}
			if(min>s[i].grade)
				min=s[i].grade,i_min=i;
		}
		cout<<s[i_max].name<<" "<<s[i_max].sno<<endl;
		cout<<s[i_min].name<<" "<<s[i_min].sno<<endl;
				
	}
	#ifndef JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
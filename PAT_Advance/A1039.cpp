#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
	string name;
	vector<int> cour_ID;
};
int find_student(const vector<student> &stu,string tmp){
	int index;
	for(index=0;index<stu.size();index++)
		if(stu[index].name==tmp) return index;
	return -1;
}
void sort_course(vector<student> &stu){
	for(int i=0;i<stu.size();i++){
		sort(stu[i].cour_ID.begin(),stu[i].cour_ID.end());
	}
}
void print(const vector<student> &stu,const vector<string> &stu_name){
	for(int i=0;i<stu_name.size();i++){
		int index=find_student(stu,stu_name[i]);
		if(index==-1){
			cout<<stu_name[i]<<" 0"<<endl;
		}
		else{
			cout<<stu[index].name<<" "<<stu[index].cour_ID.size();
			for(int j=0;j<stu[index].cour_ID.size();j++)
				cout<<" "<<stu[index].cour_ID[j];
			cout<<endl;
		}
	}
}
int main()
{
	int n,k;
	vector<student> stu;
	vector<string> stu_name;
	while(cin>>n>>k){
		int course,num,index;
		student t;
		string tmp;
		while(k--){
			cin>>course>>num;
			for(int i=0;i<num;i++){
				cin>>tmp;
				index=find_student(stu,tmp);
				t.cour_ID.clear();
				if(index==-1){
					t.name=tmp;
					t.cour_ID.push_back(course);
					stu.push_back(t);
				}
				else{
					stu[index].cour_ID.push_back(course);
				}
			}
		}
		string str;
		for(int i=0;i<n;i++){
			cin>>str;
			stu_name.push_back(str);
		}
		sort_course(stu);
		print(stu,stu_name);
		stu.clear();
		stu_name.clear();
	}
	return 0;
}
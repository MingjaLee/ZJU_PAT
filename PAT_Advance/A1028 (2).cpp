#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct person{
	string name;
	int y;
	int m;
	int d;
};
person a[100010];
bool in_range(person tmp)
{
	if(tmp.y>2014) return false;
	else if(tmp.y==2014){
		if(tmp.m>9) return false;
		else if(tmp.m==9){
			if(tmp.d>6) return false;
		}
	}
	if(tmp.y<1814) return false;
	else if(tmp.y==1814){
		if(tmp.m<9) return false;
		else if(tmp.m==9){
			if(tmp.d<6) return false;
		}
	}
	return true;
}
bool cmp(person a,person b)
{
	if(a.y<b.y)
		return true;
	else if(a.y==b.y){
		if(a.m<b.m)
			return true;
		else if(a.m==b.m){
			if(a.d<b.d)
				return true;
		}
	}
	return false;
}
int main()
{
	int n;
	person tmp;
	while(cin>>n){
		int length=0;
		for(int i=0;i<n;i++){
			cin>>tmp.name;
			scanf("%d/%d/%d",&tmp.y,&tmp.m,&tmp.d);
			if(in_range(tmp)){
				a[length++]=tmp;
			}
		}
		if(length==0)
			cout<<"0"<<endl;
		else{
			sort(a,a+length,cmp);
			cout<<length<<" "<<a[0].name<<" "<<a[length-1].name<<endl;
		}
	}
	return 0;
}
#include <iostream>
using namespace std;
typedef struct student{
	char ID[16];
	int in_h,in_m,in_s;
	int out_h,out_m,out_s;
};
bool time_cmp(int h1,int m1,int s1,int h2,int m2,int s2){
	if(h1>h2)
		return true;
	else if(h1==h2 && m1>m2)
		return true;
	else if(h1==h2 && m1==m2 && s1>s2)
		return true;
	else 
		return false;
}
int main()
{
	student tmp,first,end;
	int n;
	while(cin>>n){
		first.in_h=first.in_m=first.in_s=60;
		end.out_h=end.out_m=end.out_s=-1;
		while(n--){
			scanf("%s %2d:%2d:%2d %2d:%2d:%2d",tmp.ID,&tmp.in_h,&tmp.in_m,&tmp.in_s,&tmp.out_h,&tmp.out_m,&tmp.out_s);
			if(time_cmp(first.in_h,first.in_m,first.in_s,tmp.in_h,tmp.in_m,tmp.in_s))
				first=tmp;
			if(!time_cmp(end.out_h,end.out_m,end.out_s,tmp.out_h,tmp.out_m,tmp.out_s))
				end=tmp;
		}
		printf("%s %s\n",first.ID,end.ID);
	}
	return 0;
}
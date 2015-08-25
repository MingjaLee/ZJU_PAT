#include <iostream>
#include <cstring>
#define MSize 100010
using namespace std;
int grade[MSize];
bool school[MSize];
int main()
{
	int n;
	int sch,gra;
	int count;
	while(cin>>n){
		memset(grade,0,sizeof(grade));
		memset(school,0,sizeof(school));
		count=0;
		while(n--){
			cin>>sch>>gra;
			grade[sch]+=gra;
			if(!school[sch]){
				count++;
				school[sch]=true;
			}
		}
		int max=0,index;
		for(int i=1;i<=count;i++){
			if(max<grade[i]){
				max=grade[i];
				index=i;
			}
		}
		cout<<index<<" "<<max<<endl;	
	}
	return 0;
}
排名终于跑到第一页了，么么哒 
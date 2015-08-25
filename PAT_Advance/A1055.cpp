#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100010;
typedef struct node{
	char name[9];
	int age;
	int worth;
};
int Age[201]={0}; // the sum of a age
node person[maxn],valid[maxn];
bool cmp(node a,node b){
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%s%d%d",person[i].name,&person[i].age,&person[i].worth);
	sort(person,person+n,cmp);
	int validnum=0;
	for(int i=0;i<n;i++){
		if(Age[person[i].age]<100){
			Age[person[i].age]++;
			valid[validnum++]=person[i];
		}
	}
	int m,Amin,Amax;
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&m,&Amin,&Amax);			
		printf("Case #%d:\n",i);
		int out=0;
		for(int j=0;j<validnum && out<m;j++){
			if(valid[j].age>=Amin && valid[j].age<=Amax){
				out++;
				printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].worth);
			}
		}
		if(out==0)
			printf("None\n");
	}
	return 0;
}
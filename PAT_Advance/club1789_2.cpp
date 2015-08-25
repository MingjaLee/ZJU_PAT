#include <iostream>
#include <set>
#include <map>
using namespace std;
set<int> V;
map<int,int> father;
int findFather(int x){
	int r=x;
	while(r!=father[r])
		r=father[r];
	while(x!=father[x]){
		father[x]=r;
		x=father[x];
	}
	return r;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB)
		father[faB]=faA;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(father.count(a)==0){
			father[a]=a;
		}
		if(father.count(b)==0){
			father[b]=b;
		}
		V.insert(a);
		V.insert(b);
		Union(a,b);
	}
	int ans=0;
	set<int>::iterator it;
	for(it=V.begin();it!=V.end();it++){
		if(father[*it]!=*it)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
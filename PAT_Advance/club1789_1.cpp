#include <iostream>
#include <set>
using namespace std;
const int N=100000;
int root[N];
set<int> V;
void Init_root(){
	for(int i=0;i<N;i++)
		root[i]=i;
}
int findRoot(int x){
	int r=x;
	while(r!=root[r])
		r=root[r];
	while(x!=root[x]){
		root[x]=r;
		x=root[x];
	}
	return r;
}
void Union(int a,int b){
	int Ra=findRoot(a);
	int Rb=findRoot(b);
	if(Ra!=Rb)
		root[Rb]=Ra;
}
int main()
{
	int a,b;
	Init_root();
	while(scanf("%d%d",&a,&b)!=EOF){
		V.insert(a);
		V.insert(b);
	//	cout<<"after insert"<<endl;
		Union(a,b);
	//	cout<<"after union"<<endl;
	}
	set<int>::iterator it;
	int ans=0;
	for(it=V.begin();it!=V.end();it++){
		if(root[*it]!=*it)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
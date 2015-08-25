#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=10010;
vector<int> G[N];
int father[N];
bool isRoot[N]={false};
void Init_Father(int n){
	for(int i=1;i<=n;i++)
		father[i]=i;
}
int findFather(int x){
	int a=x;
	while(x!=father[x])
		x=father[x];
	while(a!=father[a]){
		father[a]=x;
		a=father[a];
	}
	return x;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB)
		father[faA]=faB;
}
int numBlock(int n){
	for(int i=1;i<=n;i++)
		isRoot[findFather(i)]=true;
	int num=0;
	for(int i=1;i<=n;i++)
		num+=isRoot[i];
	return num;
}
int maxH=0;
vector<int> temp,ans;
void DFS(int index,int height,int pre){
	if(height>maxH){
		temp.clear();
		temp.push_back(index);
		maxH=height;
	}
	else if(height==maxH){
		temp.push_back(index);
	}
	for(int i=0;i<G[index].size();i++){
		if(G[index][i]!=pre)
			DFS(G[index][i],height+1,index);
	}
}
int main()
{
	int n,a,b;
	scanf("%d",&n);
	Init_Father(n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b);
	}
	int NBlock=numBlock(n);
	if(NBlock!=1){
		printf("Error: %d components\n",NBlock);
	}
	else{
		DFS(1,1,-1);
		ans=temp;
		DFS(ans[0],1,-1);
		for(int i=0;i<temp.size();i++)
			ans.push_back(temp[i]);
		sort(ans.begin(),ans.end());
		printf("%d\n",ans[0]);
		for(int i=1;i<ans.size();i++){
			if(ans[i]!=ans[i-1])
				printf("%d\n",ans[i]);
		}
	}
	return 0;
}
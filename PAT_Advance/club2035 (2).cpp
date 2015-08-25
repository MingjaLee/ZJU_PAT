#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int N=26*26*26+10;
struct node{
	int ID;
	int member;
};
vector<int> G[N];
vector<node> Ans;
set<int> V;
int weight[N]={0};
bool visit[N]={false};
int n,k;
int getID(char str[]){
	int ret=0;
	for(int i=0;i<3;i++)
		ret=ret*26+str[i]-'A';
	return ret;
}
void getName(char str[],int ID){
	for(int i=2;i>=0;i--){
		str[i]=ID%26+'A';
		ID/=26;
	}
	str[3]='\0';
}
void DFS(int u,int &sum,int &maxW,int &maxW_ID,int &member){
	visit[u]=true;
	sum+=weight[u];
	member++;
	if(maxW<weight[u]){
		maxW=weight[u];
		maxW_ID=u;
	}
	for(int i=0;i<G[u].size();i++){
		if(visit[G[u][i]]==false){
			DFS(G[u][i],sum,maxW,maxW_ID,member);
		}
	}
}
void DFSTraveral(){
	set<int>::iterator it;
	for(it=V.begin();it!=V.end();it++){
		if(visit[*it]==false){
			int sum=0,maxW=-1,maxW_ID,member=0;
			DFS(*it,sum,maxW,maxW_ID,member);
			//cout<<"Sum="<<sum<<endl;
			sum>>=1;
			if(member>2 && sum>k){
				node temp;
				temp.ID=maxW_ID;
				temp.member=member;
				Ans.push_back(temp);
			}
		}
	}
}

bool cmp(node a,node b){
	return a.ID<b.ID;
}
void output(){
	sort(Ans.begin(),Ans.end(),cmp);
	printf("%d\n",Ans.size());
	char name[4];
	for(int i=0;i<Ans.size();i++){
		getName(name,Ans[i].ID);
		printf("%s %d\n",name,Ans[i].member);
	}
}

int main()
{

	scanf("%d%d",&n,&k);
	char str1[4],str2[4];
	int ID1,ID2,w;
	for(int i=0;i<n;i++){
		scanf("%s%s%d",str1,str2,&w);
		ID1=getID(str1);
		ID2=getID(str2);
		weight[ID1]+=w;
		weight[ID2]+=w;
		G[ID1].push_back(ID2);
		G[ID2].push_back(ID1);
		V.insert(ID1);
		V.insert(ID2);
	}
	DFSTraveral();
	output();
	return 0;
}
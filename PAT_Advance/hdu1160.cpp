#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#define TDEBUG
using namespace std;
const int N=1005;
struct Mice{
	int weight;
	int speed;
	int ID;
}mice[N];
int dp[N],pre[N];
int num=0,maxlen=1,maxIndex=1;
bool cmp(Mice a,Mice b){
	if(a.weight!=b.weight) return a.weight<b.weight;
	else if(a.speed!=b.speed) return a.speed>b.speed;
}
int main()
{
	int w,s;
	while(scanf("%d%d",&w,&s)!=EOF){
		mice[++num].weight=w;
		mice[num].speed=s;
		mice[num].ID=num;
	}
	sort(mice+1,mice+num+1,cmp);
	#ifndef TDEBUG
	for(int i=1;i<=num;i++){
		printf("%d %d %d\n",mice[i].weight,mice[i].speed,mice[i].ID);
	}
	#endif
	for(int i=1;i<=num;i++)
		pre[i]=0;
	for(int i=1;i<=num;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(mice[j].weight<mice[i].weight && mice[j].speed>mice[i].speed && dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
				pre[i]=j;
				if(maxlen<=dp[i]){
					maxlen=dp[i];
					maxIndex=i;
				}
			}
		}
	}
	printf("%d\n",maxlen);
	stack<int> st;
	int ix=maxIndex;
	st.push(mice[ix].ID);
	while(pre[ix]!=0){
		ix=pre[ix];
		st.push(mice[ix].ID);
	}
	while(!st.empty()){
		printf("%d\n",st.top());
		st.pop();
	}
	return 0;
}
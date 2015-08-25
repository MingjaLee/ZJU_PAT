#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxNode=1005;
struct Window{
	int endTime,popTime;
	queue<int> q;
}window[21];
int n,m,k,q,query[maxNode];
int ans[maxNode],serveTime[maxNode];
inline int convertToMinute(int h,int m){
	return h*60+m;
}
int main()
{
	int index=0;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=0;i<k;i++)
		scanf("%d",&serveTime[i]);
	for(int i=0;i<q;i++)
		scanf("%d",&query[i]);
	for(int i=0;i<n;i++)
		window[i].endTime=window[i].popTime=convertToMinute(8,0);
	int ed=min(n*m,k);
	for(int i=0;i<ed;i++){
		window[index%n].q.push(index);
		window[index%n].endTime+=serveTime[index];
		if(index<n) window[index].popTime+=serveTime[index];
		ans[index]=window[index%n].endTime;
		index++;
	}
	for(;index<k;index++){
		int ix=-1,MinpopTime=1<<30;
		for(int i=0;i<n;i++){
			if(MinpopTime>window[i].popTime)
				MinpopTime=window[ix=i].popTime;
		}
		Window &W=window[ix];
		W.q.pop();
		W.q.push(index);
		W.endTime+=serveTime[index];
		W.popTime+=serveTime[W.q.front()];
		ans[index]=W.endTime;
	}
	for(int i=0;i<q;i++){
		int que=query[i]-1;
		if(ans[que]-serveTime[que]>=convertToMinute(17,0))
			printf("Sorry\n");
		else
			printf("%02d:%02d\n",ans[que]/60,ans[que]%60);
	}
	return 0;
}
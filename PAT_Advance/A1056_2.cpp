#include <iostream>
#include <queue>
using namespace std;
const int N=1010;
struct Mouse{
	int weight;
	int rank;
}mouse[N];
int main()
{
	int NP,NG,order;
	queue<int> q;
	while(scanf("%d%d",&NP,&NG)!=EOF){
		for(int i=0;i<NP;i++)
			scanf("%d",&mouse[i].weight);
		for(int i=0;i<NP;i++){
			scanf("%d",&order);
			q.push(order);
		}
		int temp=NP,group;
		while(q.size()!=1){
			group=temp/NG;
			if(temp%NG!=0) group++;
			for(int i=0;i<group;i++){
				int k=q.front();
				for(int j=0;j<NG;j++){
					if(i*NG+j>=temp) break;
					int front=q.front();
					if(mouse[k].weight<mouse[front].weight)
						k=front;
					mouse[front].rank=group+1;
					q.pop();
				}
				q.push(k);
			}
			temp=group;
		}//while
		mouse[q.front()].rank=1;
		for(int i=0;i<NP;i++){
			printf("%d",mouse[i].rank);
			if(i==NP-1) printf("\n");
			else printf(" ");
		}
		while(!q.empty())
			q.pop();
	}
	return 0;
}
#include <iostream>
#include <queue>
using namespace std;
const int N=1010;
const int M=100000;
struct mouse{
	int weight;
	int rank;
}m[N];
int Q[M];
int front,rear;
int Q_length(){
	return rear-front;
}
int main()
{
	int NP,NG,order;
	while(scanf("%d%d",&NP,&NG)!=EOF){
		front=rear=-1;
		for(int i=0;i<NP;i++)
			scanf("%d",&m[i].weight);
		for(int i=0;i<NP;i++){
			scanf("%d",&order);
			Q[++rear]=order;
		}
		int last=rear;
		int temp=Q_length(),group;
		while(temp!=1){
			if(temp%NG==0) group=temp/NG;
			else group=temp/NG+1;
			int turn=0,k=Q[front+1];
			while(front!=last){
				if(m[k].weight<m[Q[front+1]].weight)
					k=Q[front+1];
				turn++;
				m[Q[++front]].rank=group+1;
				if(turn%NG==0 || front==last){
					Q[++rear]=k;
					k=Q[front+1];
				}
			}
			last=rear;
			temp=Q_length();
		}
		m[Q[++front]].rank=1;
		//output
		for(int i=0;i<NP;i++){
			printf("%d",m[i].rank);
			if(i==NP-1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
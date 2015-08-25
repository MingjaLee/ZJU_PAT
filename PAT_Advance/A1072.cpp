#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1015;
const int INF=1<<29;
int G[N][N],dist[N];
bool visit[N];
int Gs=-1;//目标Gas station 
double minNum=-1,tempMinNum,avg=INF,tempAvg; //minNum,avg为最终值，temp*为中间变量 
bool solution=false;
int numHouse,numGas,numRoad,DS,numV;

int getID(char str[]){
	int ID=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]!='G')
			ID = ID * 10 + (str[i] - '0');
	}
	if(str[0] == 'G') return numHouse + ID;
	else return ID;
}

void Init(){
	fill(dist,dist+N,INF);
	fill(visit,visit+N,0);
}
void Dijistra(int s){
	Init();
	dist[s]=0;
	for(int i=1;i<=numV;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=numV;j++){
			if(!visit[j] && dist[j]<MIN)
				MIN=dist[u=j];
		}
		if(u==-1) return;
		visit[u]=true;
		for(int v=1;v<=numV;v++){
			if(!visit[v] && G[u][v]!=INF && dist[u]+G[u][v]<dist[v])
				dist[v]=dist[u]+G[u][v];
		}
	}
}
bool cal_dist(){//每次Dijistra后的比较， return bool型 
	tempMinNum=INF;
	tempAvg=0;
	for(int i=1;i<=numHouse;i++){
		if(dist[i]>DS) return false;
		tempAvg+=dist[i]*1.0/numHouse;
		if(dist[i]<tempMinNum)
			tempMinNum=dist[i];
	}
//	tempAvg/=numHouse;
	return true;
}
int main()
{
	scanf("%d%d%d%d",&numHouse,&numGas,&numRoad,&DS);
	numV=numHouse+numGas;
	fill(G[0],G[0]+N*N,INF);
	int u,v,w;
	char str1[5],str2[5];
	for(int i=0;i<numRoad;i++){
		scanf("%s %s %d",str1,str2,&w);
		u=getID(str1);
		v=getID(str2);
		G[u][v]=G[v][u]=w;
	}
	for(int i=numHouse+1;i<=numV;i++){
		Dijistra(i);
		if(cal_dist()){
			solution=true;
//			cout<<"G"<<i-numHouse<<endl;
//			printf("%.1f %.1f\n",tempMinNum*1.0,tempAvg);
			if(tempMinNum>minNum){
				minNum=tempMinNum;
				avg=tempAvg;
				Gs=i;
			}
			else if(tempMinNum==minNum){
				if(avg>tempAvg){
					avg=tempAvg;
					Gs=i;
				}
			}
		}
	}
	//output
//	cout<<"output"<<endl;
	if(solution==false)
		printf("No Solution\n");
	else{
		printf("G%d\n",Gs-numHouse);
		printf("%.1f %.1f\n",minNum,avg);
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define TDEBUG
using namespace std;
const int maxn=10005;
const int maxt=205;
const int INF=1<<30;
struct players{
	int arriveTime;
	int playTime;
	int waitTime;
	int serveTime;
	players(){
		waitTime=0;
	}
}p[maxn];
struct Table{
	int endTime;
	int serveNum;
	int VIP;
	bool use;
}table[maxt];
int n,k,m,openTime,closeTime;
int indexQ=0,indexP=0;
vector<players> playVIP;
vector<players> Q;
vector<players> Out;
int convertToSeconds(int h,int m,int s){
	return h*3600+m*60+s;
}
void convertToTime(int second,int &h,int &m,int &s){
	h=second/3600;
	second%=3600;
	m=second/60;
	s=second%60;
	return;
}
bool cmp(players a,players b){
	return a.arriveTime<b.arriveTime;
}
bool cmp1(players a,players b){
	return a.serveTime<b.serveTime;
}
int findVipTable(){
	int ret=-1;
	for(int i=1;i<=k;i++){
		if(table[i].VIP==1 && table[i].use==0){
			ret=i;
			break;
		}
	}
	return ret;
}
int findTable(){
	for(int i=1;i<=k;i++)
		if(table[i].use==false) return i;
	return -1;
}
void countOne(int i,players &tmp){
	table[i].use=true;
	table[i].serveNum++;
	if(tmp.arriveTime<table[i].endTime){
		tmp.waitTime=table[i].endTime-tmp.arriveTime;
		tmp.serveTime=table[i].endTime;
		table[i].endTime+=tmp.playTime;		
	}
	else{
		tmp.waitTime=0;
		tmp.serveTime=tmp.arriveTime;
		table[i].endTime=tmp.serveTime+tmp.playTime;
	}
}
int main()
{
	openTime=convertToSeconds(8,0,0);
	closeTime=convertToSeconds(21,0,0);
	scanf("%d",&n);
	int h,m,s,playTime,tag;
	players tmp;
	for(int i=1;i<=n;i++){
		scanf("%d:%d:%d %d %d",&h,&m,&s,&playTime,&tag);
		int arriveTime=convertToSeconds(h,m,s);
		if(arriveTime>=closeTime) continue;
		tmp.arriveTime=arriveTime;
		tmp.playTime=playTime<120 ? playTime*60 : 7200;
		if(tag==0)	Q.push_back(tmp);
		else playVIP.push_back(tmp);
	}
	sort(Q.begin(),Q.end(),cmp);
	sort(playVIP.begin(),playVIP.end(),cmp);
	scanf("%d%d",&k,&m);
	for(int i=0;i<m;i++){
		int VIPID;
		scanf("%d",&VIPID);
		table[VIPID].VIP=1;
	}
	// init Table
	for(int i=0;i<maxt;i++){
		table[i].endTime=openTime;
		table[i].serveNum=0;
		table[i].use=false;
	}
	#ifndef TDEBUG
	cout<<playVIP.size()<<endl;
	for(int i=0;i<playVIP.size();i++){
		int h,m,s;
		convertToTime(playVIP[i].arriveTime,h,m,s);
		printf("%02d:%02d:%02d %d\n",h,m,s,playVIP[i].playTime/60);
	}
	cout<<Q.size()<<endl;
	for(int i=0;i<Q.size();i++){
		int h,m,s;
		convertToTime(Q[i].arriveTime,h,m,s);
		printf("%02d:%02d:%02d %d\n",h,m,s,Q[i].playTime/60);
	}
	for(int i=1;i<=k;i++){
		printf("%d:%d ",i,table[i].VIP);
	}
	printf("\n");
	#endif
	/***********前k个处理****************/
	for(int j=1;j<=k && j<= Q.size()+playVIP.size();j++){
		int useVIP=findVipTable();
		if(indexP<playVIP.size() && playVIP[indexP].arriveTime<=openTime && useVIP!=-1){
			countOne(useVIP,playVIP[indexP]);
			Out.push_back(playVIP[indexP++]);
		}
		else if(indexQ<Q.size() && Q[indexQ].arriveTime<=openTime){
			int i=findTable();
			countOne(i,Q[indexQ]);
			Out.push_back(Q[indexQ++]);
		}
		else if(indexP<playVIP.size() && indexQ<Q.size()){
			if(Q[indexQ].arriveTime<playVIP[indexP].arriveTime){
				int i=findTable();
				countOne(i,Q[indexQ]);
				Out.push_back(Q[indexQ++]);
			}
			else{
				if(useVIP!=-1){
					countOne(useVIP,playVIP[indexP]);
					Out.push_back(playVIP[indexP++]);
				}
				else{
					int i=findTable();
					countOne(i,playVIP[indexP]);
					Out.push_back(playVIP[indexP++]);
				}
			}
		}
		else if(indexQ<Q.size()){
			int i=findTable();
			countOne(i,Q[indexQ]);
			Out.push_back(Q[indexQ++]);
		}
		else{
			int i=findTable();
			countOne(i,playVIP[indexP]);
			Out.push_back(playVIP[indexP++]);
		}
	}//前k个
	/***********k个之后的处理****************/
	for(int j=k+1;j<=Q.size()+playVIP.size();j++){
		int ix=-1,MinT=INF;
		for(int i=1;i<=k;i++){
			if(MinT>table[i].endTime)
		 		MinT=table[ix=i].endTime;
		}
		if(table[ix].endTime>=closeTime) break;
		if(table[ix].VIP==1 && indexP<playVIP.size() 
			&& table[ix].endTime>=playVIP[indexP].arriveTime){
			countOne(ix,playVIP[indexP]);
			Out.push_back(playVIP[indexP++]);
		}
		else if(indexQ<Q.size() && indexP<playVIP.size()){
			if(Q[indexQ].arriveTime<playVIP[indexP].arriveTime){
				countOne(ix,Q[indexQ]);
				Out.push_back(Q[indexQ++]);
			}
			else{
				countOne(ix,playVIP[indexP]);
				Out.push_back(playVIP[indexP++]);
			}
		}
		else if(indexQ<Q.size()){
			countOne(ix,Q[indexQ]);
			Out.push_back(Q[indexQ++]);
		}
		else{
			countOne(ix,playVIP[indexP]);
			Out.push_back(playVIP[indexP++]);
		}
	}//end for()
	/***********Output************/
	sort(Out.begin(),Out.end(),cmp1);
	for(int i=0;i<Out.size();i++){
		if(Out[i].serveTime>=closeTime) break;
		int h,m,s;
		convertToTime(Out[i].arriveTime,h,m,s);
		printf("%02d:%02d:%02d ",h,m,s);
		convertToTime(Out[i].serveTime,h,m,s);
		printf("%02d:%02d:%02d ",h,m,s);
		printf("%d\n",(Out[i].waitTime+30)/60);	
	}
	for(int i=1;i<=k;i++){
		printf("%d",table[i].serveNum);
		if(i<k) printf(" ");
		else printf("\n");
	}
	return 0;
}
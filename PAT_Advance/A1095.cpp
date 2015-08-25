#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
const int N=1e4+5;
struct node{
	int ID;
	int Time;
	string status;
	int flag;
}Node[N];
map<string,int> CardToID;
map<int,string> IDToCard;
int stayTime[N]={0};
int inTime[N];
int n,k,numID=0;
int valid=0;
int NewID(string card){
	int ID;
	if(CardToID.find(card) == CardToID.end()){
		ID=numID++;
		CardToID[card]=ID;
		IDToCard[ID]=card;
	}
	else{
		ID=CardToID[card];
	}
	return ID;
}
int change(int h,int m,int s){
	return h*3600+m*60+s;
}
bool cmp1(node a,node b){
	if(a.ID!=b.ID) return a.ID<b.ID;
	else if(a.ID==b.ID) return a.Time<b.Time;
}
bool cmp2(node a,node b){
	if(a.flag==0 || b.flag==0) return a.flag>b.flag;
	else if(a.flag==1 && b.flag==1){
		return a.Time<b.Time;
	}
}
bool cmp3(int a,int b){
	return IDToCard[a]<IDToCard[b];
}
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	string card;
	for(int i=0;i<n;i++){
		int hh,mm,ss;
		cin>>card;
		Node[i].ID=NewID(card);
		scanf("%d:%d:%d",&hh,&mm,&ss);
		Node[i].Time=change(hh,mm,ss);
		cin>>Node[i].status;
		Node[i].flag=0;
	}
	sort(Node,Node+n,cmp1);
	for(int i=0;i<n-1;i++){
		if(Node[i].ID==Node[i+1].ID && Node[i].status=="in" && Node[i+1].status=="out"){
			Node[i].flag=Node[i+1].flag=1;
			valid+=2;
		}
	}
	sort(Node,Node+n,cmp2);
	int index=0;
	int inCars=0;
	//memset(inTime,-1,sizeof(inTime));
	for(int i=0;i<k;i++){
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int t=change(hh,mm,ss);
		while(index<valid){
			if(Node[index].Time>t) break;
			int ID=Node[index].ID;
			if(Node[index].status=="in"){
				inTime[ID]=Node[index].Time;
				inCars++;
				index++;
			}
			else{
				stayTime[ID]+=Node[index].Time-inTime[ID];
				inCars--;
				index++;
			}
		}
		printf("%d\n",inCars);
	}
	while(index<valid){
		int ID=Node[index].ID;
		if(Node[index].status=="in"){
			inTime[ID]=Node[index].Time;
		}
		else{
			stayTime[ID]+=Node[index].Time-inTime[ID];
		}
		index++;
	}
	int maxTime=0;
	vector<int> AnsCar;
	for(int i=0;i<numID;i++){
		if(maxTime<stayTime[i]){
			maxTime=stayTime[i];
			AnsCar.clear();
			AnsCar.push_back(i);
		}
		else if(maxTime==stayTime[i]){
			AnsCar.push_back(i);
		}
	}
	sort(AnsCar.begin(),AnsCar.end(),cmp3);
	for(int i=0;i<AnsCar.size();i++){
		cout<<IDToCard[AnsCar[i]]<<" ";
	}
//	cout<<maxTime<<endl;
	int h,m,s;
	s=maxTime%60;
	maxTime/=60;
	m=maxTime%60;
	maxTime/=60;
	h=maxTime%60;
	printf("%02d:%02d:%02d\n",h,m,s);
	return 0;
}
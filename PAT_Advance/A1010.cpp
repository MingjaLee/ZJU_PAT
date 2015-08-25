#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long LL;
LL INF=(1LL<<63)-1;
LL HashTable[256];
void InitHash(){
	for(char ch='0';ch<='9';ch++)
		HashTable[ch]=ch-'0';
	for(char ch='a';ch<='z';ch++)
		HashTable[ch]=ch-'a'+10;
}
LL get_num10(string str,LL radix,LL t){
	LL num=0;
	for(int i=0;i<str.size();i++){
		num=num*radix+HashTable[str[i]];
		if(num<0 || num>t)
			return -1;
	}
	return num;
}
LL least_radix(string N2){
	LL ans=-1;
	for(int i=0;i<N2.size();i++){
		if(ans<HashTable[N2[i]])
		ans=HashTable[N2[i]];
	}
	return ans+1;
}
int cmp(string N2,LL radix,LL t){
	LL num=get_num10(N2,radix,t);
	if(num<0) return 1;
	if(num<t) return -1;
	else if(num==t) return 0;
	else
		return 1;
}
LL binarySearch(string N2,LL low,LL high,LL num1){
	LL mid,num2;
	while(low<=high){
		mid=(low+high)/2;
		int flag=cmp(N2,mid,num1);
		if(flag==0) return mid;
		else if(flag==-1) low=mid+1;
		else high=mid-1;
	}
	return -1;
}
string N1,N2,tmp;
int tag,radix;
int main()
{
	InitHash();
	cin>>N1>>N2;	
	scanf("%d%d",&tag,&radix);
	if(tag==2){
		tmp=N1;
		N1=N2;
		N2=tmp;
	}
	LL t=get_num10(N1,radix,INF);
	LL low=least_radix(N2);
	LL high=max(low,t)+1;
	LL ans=binarySearch(N2,low,high,t);
	if(ans==-1)
		cout<<"Impossible"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
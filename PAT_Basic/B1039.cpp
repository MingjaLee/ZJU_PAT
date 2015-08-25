#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
const int N=258;

int HashTable[N]={0};

int main()	
{
	string str,buy;
	cin>>str>>buy;
	int len1=str.size();
	int len2=buy.size();
	for(int i=0;i<len1;i++){
		HashTable[str[i]]++;
	}
	int need=0;
	for(int i=0;i<len2;i++){
		char ch=buy[i];
		if(--HashTable[ch] < 0) need++;
	}
	if(need > 0){
		printf("No %d\n",need);
	}
	else{
		printf("Yes %d\n",len1-len2);
	}
	return 0;
}
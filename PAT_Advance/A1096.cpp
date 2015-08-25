#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
int n;
int AnsNum,tempNum;
int AnsSt;
bool getNewNum(int st,int n){
	int m=n;
	tempNum=0;
	while(1){
		if( m%st != 0 || m < st) break;
		m/=st;
		tempNum++;
		st++;
	}
	if(AnsNum < tempNum){
		AnsNum=tempNum;
		return true;
	}
	else return false;
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		AnsNum=0;
		int mid=(int)sqrt(n);
		for(int i=2;i<=mid;i++){
			if(n%i==0 && getNewNum(i,n)){
				AnsSt=i;
			}
		}
		if(AnsNum!=0){
			printf("%d\n",AnsNum);
			for(int i=0;i<AnsNum;i++){
				if(i>0) printf("*");
				printf("%d",AnsSt+i);
			}
			printf("\n");			
		}
		else{
			printf("1\n%d\n",n);
		}

	}
	return 0;
}
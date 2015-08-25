#include <iostream>
#include <cctype>
using namespace std;
const int N=1010;
int Hash[N];
int getID(char ch){
	int ID;
	if(isdigit(ch)) ID=ch-'0';
	else if(islower(ch)) ID=ch-'a'+10;
	else ID=ch-'A'+26+10;
	return ID;
}
int main()
{
	char str[N],Eva[N];
	scanf("%s",str);
	scanf("%s",Eva);
	int len1=strlen(str);
	int len2=strlen(Eva);
	for(int i=0;i<len1;i++){
		Hash[getID(str[i])]++;
	}
	int flag=len2;
	for(int i=0;i<len2;i++){
		int ID=getID(Eva[i]);
		if(Hash[ID]<=0) break;
		else{
			Hash[ID]--;
			flag--;
		}
	}
	if(flag==0){
		printf("Yes %d\n",len1-len2);
	}
	else printf("No %d\n",flag);
	return 0;
}
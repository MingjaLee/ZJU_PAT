#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	bool HashTable[128];
	char s1[10010],s2[10010];
	while(gets(s1)!=NULL){
		gets(s2);
		memset(HashTable,0,sizeof(HashTable));
		for(int i=0;s2[i]!='\0';i++)
			HashTable[s2[i]]=true;
		for(int i=0;s1[i]!='\0';i++)
			if(HashTable[s1[i]]==false)
				printf("%c",s1[i]);
		printf("\n");
	}
	return 0;
}
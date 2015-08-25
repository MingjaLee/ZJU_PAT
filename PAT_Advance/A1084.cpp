#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
bool in_wrong(char wrong[],int len_w,char ch){
	ch=toupper(ch);
	for(int i=0;i<len_w;i++)
		if(wrong[i]==ch)
			return true;
	return false;
}
int main()
{
	char str1[81],str2[81],wrong[81];
	int len_str1,len_str2,len_w;
	bool HashTable[128];
	while(gets(str1)!=NULL){
		gets(str2);
		memset(HashTable,0,sizeof(HashTable));
		len_str1=strlen(str1);
		len_str2=strlen(str2);
		len_w=0;
		int i=0,j=0;
		while(j<len_str2){
			if(str1[i]!=str2[j]){
				char tc=toupper(str1[i]);
				if(HashTable[tc]==false){
					wrong[len_w++]=tc;
					HashTable[tc]=true;					
				}
				i++;
			}
			else{
				i++,j++;
			}
		}
		while(i<len_str1){
			char tc=toupper(str1[i]);
			if(HashTable[tc]==false){
				wrong[len_w++]=tc;
				HashTable[tc]=true;				
			}
			i++;
		}
		for(int i=0;i<len_w;i++)
			printf("%c",wrong[i]);
		printf("\n");
	}
	return 0;
}
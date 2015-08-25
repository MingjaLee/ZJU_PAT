#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int N=100010;
bool HashTable[128];
void Init_Hash(char wrong[],int len_w){
	memset(HashTable,0,sizeof(HashTable));
	for(int i=0;i<len_w;i++)
		HashTable[wrong[i]]=true;
}
int main()
{
	char wrong[N],str[N],out[N];
	int len_w,len_str,len_out;
	while(gets(wrong)!=NULL){
		gets(str);
		len_w=strlen(wrong);
		len_str=strlen(str);
		len_out=0;
		Init_Hash(wrong,len_w);
		bool add_fail=HashTable['+'];
		int i=0;
		while(i<len_str){
			if(isupper(str[i]) && add_fail)
				i++;
			else if(HashTable[toupper(str[i])])
				i++;
			else
				printf("%c",str[i++]);
		}
		printf("\n");
	}
	return 0;
}
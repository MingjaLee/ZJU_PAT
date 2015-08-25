#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N=21;
struct bign
{
	int len;
	int num[N];
};
int Hash[10]={0};
bign changeToBign(char str[]){
	int len=strlen(str);
	bign ret;
	ret.len=len;
	for(int i=0;i<len;i++){
		ret.num[len-1-i] = (str[i] - '0');
	}
	return ret;
}

void ShowBign(const bign &a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.num[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	char str[N];
	while(scanf("%s",str)!=EOF){
		bign a=changeToBign(str);
		ShowBign(a);
	}
	return 0;
}
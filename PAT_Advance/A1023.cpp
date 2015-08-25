#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct bignum{
	int d[21];
	int len;
	bignum(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
int account[10];// 统计origin中1~9各个数字出现次数 
char origin[21];
bignum str_to_bign(char str[]){
	bignum res;
	res.len=strlen(str);
	memset(account,0,sizeof(account));
	for(int i=0;i<res.len;i++){
		res.d[i]=str[res.len-i-1]-'0';
		account[res.d[i]]++;		
	}
	return res;
}
bignum multi(bignum a,int b){
	bignum res;
	int carray=0;
	for(int i=0;i<a.len;i++){
		int temp=a.d[i]*b+carray;
		res.d[res.len++]=temp%10;
		carray=temp/10;
	}
	while(carray!=0){
		res.d[res.len++]=carray%10;
		carray/=10;
	}
	return res;
}
bool isNumber(bignum a){
	if(a.len!=strlen(origin))
		return false;
	int num[10]={0};
	for(int i=0;i<a.len;i++)
		num[a.d[i]]++;
	for(int i=0;i<10;i++)
		if(num[i]!=account[i])
			return false;
	return true;
}
void printbign(bignum a){
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
}
int main()
{
	while(scanf("%s",origin)!=EOF){
		bignum a=str_to_bign(origin);
		a=multi(a,2);
		if(isNumber(a))
			printf("Yes\n");
		else
			printf("No\n");
		printbign(a);
		printf("\n");
	}
	return 0;
}
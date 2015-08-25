#include <iostream>
#include <cstring>
using namespace std;
struct bignum{
	int d[1000];
	int len;
	bignum(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bignum ChangeToBig(char str[]){
	bignum res;
	res.len=strlen(str);
	for(int i=0;i<res.len;i++)
		res.d[i]=str[res.len-1-i]-'0';
	return res;
}
bignum add(bignum a,bignum b){
	bignum res;
	int carray=0;
	for(int i=0;i<a.len || i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carray;
		res.d[res.len++]=temp%10;
		carray=temp/10;
	}
	if(carray!=0)
		res.d[res.len++]=carray;
	return res;
}
bignum reverseNum(bignum a){
	bignum res;
	res.len=a.len;
	for(int i=0;i<res.len;i++)
		res.d[i]=a.d[res.len-1-i];
	return res;
}
bool isPalin(bignum a){
	int i=0,j=a.len-1;
	while(i<=j){
		if(a.d[i++]!=a.d[j--])
			return false;
	}
	return true;
}
void printBig(bignum a){
	for(int i=a.len-1;i>=0;i--)
		printf("%d",a.d[i]);
}
int main()
{
	char str[1000];
	int k;
	while(scanf("%s%d",str,&k)!=EOF){
		bignum a=ChangeToBig(str);
		int step=0;
		bignum b;
		while(step<k && !isPalin(a)){
			b=reverseNum(a);
			a=add(a,b);
			step++;
		}
		printBig(a);
		printf("\n%d\n",step);
	}
	return 0;
}
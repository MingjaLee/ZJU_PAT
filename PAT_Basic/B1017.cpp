#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
struct bignum{
	int d[N];
	int len;
	bignum(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bignum change(char str[]){
	bignum res;
	res.len=strlen(str);
	for(int i=0;i<res.len;i++)
		res.d[i]=str[res.len-1-i]-'0';
	return res;
}
bignum divide(bignum a,int b,int &r){
	bignum res;
	res.len=a.len;
	for(int i=res.len-1;i>=0;i--){
		r=r*10+a.d[i];
		if(r<b)
			res.d[i]=0;
		else{
			res.d[i]=r/b;
			r%=b;
		}
	}
	while(res.len>1 && res.d[res.len-1]==0)
		res.len--;
	return res;
}
void printbign(bignum t){
	for(int i=t.len-1;i>=0;i--)
		printf("%d",t.d[i]);
}
int main()
{
	char A[N];
	int B;
	while(scanf("%s%d",A,&B)!=EOF){
		bignum a,q;
		int r=0;
		a=change(A);
		q=divide(a,B,r);
		printbign(q);
		printf(" %d\n",r);		
	}
	return 0;
}
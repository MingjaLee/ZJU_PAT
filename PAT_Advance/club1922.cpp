#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=105;
struct bign{
	int num[N];
	int len;
	bign(){
		memset(num,0,sizeof(num));
		len=0;
	}
};
struct Float{
	bign Int;
	bign Point;
};
bign AddBignInt(const bign &a, const bign &b,int carry){
	bign c;
//	cout<<"int Int Carry="<<carry<<endl;
	c.len=max(a.len,b.len);
	int ix=0;
	while(ix<a.len && ix<b.len){
		c.num[ix]=a.num[ix]+b.num[ix]+carry;
		carry=c.num[ix]/10;
		c.num[ix]%=10;
		ix++;
	}
	while(ix<a.len){
		c.num[ix]=a.num[ix]+carry;
		carry=c.num[ix]/10;
		c.num[ix]%=10;
		ix++;
	}
	while(ix<b.len){
		c.num[ix]=b.num[ix]+carry;
		carry=c.num[ix]/10;
		c.num[ix]%=10;
		ix++;
	}
	if(carry!=0) c.num[c.len++]=carry;
	return c;
}
bign AddBignPoint(const bign &a,const bign &b,int &ret){
	bign c;
	int carry=0;
	if(a.len==b.len){
		for(int ix=a.len-1;ix>=0;ix--){
			c.num[ix]=a.num[ix]+b.num[ix]+carry;
			carry=c.num[ix]/10;
			c.num[ix]%=10;
		}
		c.len=a.len;
		//去小数的后缀0
		for(int i=c.len-1;i>=0;i--){
			if(c.num[i]!=0) break;
			else
				c.len--;
		}
	}
	else{
		bign A,B;
		if(a.len<b.len) A=a,B=b;
		else A=b,B=a;
		c.len=B.len;
		for(int i=B.len-1;i>=A.len;i--)
			c.num[i]=B.num[i];
		for(int ix=A.len-1;ix>=0;ix--){
			c.num[ix]=A.num[ix]+B.num[ix]+carry;
			carry=c.num[ix]/10;
			c.num[ix]%=10;
		}
	}
	ret=carry;
	return c;
}

Float AddFloat(const Float &a,const Float &b){
	Float c;
	int carry=0;
	c.Point=AddBignPoint(a.Point,b.Point,carry);
	c.Int=AddBignInt(a.Int,b.Int,carry);
	return c;
}

void changeToFloat(Float &f,char str[]){
	bign &Int=f.Int,&Point=f.Point;
	int index=0;
	for(;index<strlen(str);index++){
		if(str[index]=='.') break;
	}
	for(int i=index-1;i>=0;i--){
		Int.num[Int.len++]=str[i]-'0';
	}
	// 去整数前缀0 
	for(int i=Int.len-1;i>0;i--){
		if(Int.num[i]!=0) break;
		else Int.len--;
	}
	index++;
	for(;index<strlen(str);index++){
		Point.num[Point.len++]=str[index]-'0';
	}
	// 去小数后缀0
	for(int i=Point.len-1;i>=0;i--){
		if(Point.num[i]!=0) break;
		else Point.len--;
	}
}
void showFloat(const Float &f){
	const bign &Int=f.Int,&Point=f.Point;
	for(int i=Int.len-1;i>=0;i--)
		printf("%d",Int.num[i]);
	if(Point.len>0){
		printf(".");
		for(int i=0;i<Point.len;i++)
			printf("%d",Point.num[i]);
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Float a,b,c;
		char str1[N],str2[N];
		scanf("%s",str1);
		changeToFloat(a,str1);
		scanf("%s",str2);
		changeToFloat(b,str2);
		c=AddFloat(a,b);
		showFloat(c);
	}
	return 0;
}
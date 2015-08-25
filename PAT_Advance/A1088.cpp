#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
typedef struct Fraction{
	LL up,down;
};
LL gcd(LL a,LL b){
	return b==0 ? a : gcd(b,a%b);
}
Fraction reduction(Fraction res){
	if(res.down<0){
		res.down=-res.down;
		res.up=-res.up;
	}
	else if(res.up==0)
		res.down==1;
	else{
		LL d=gcd(abs(res.up),res.down);
		res.up/=d;
		res.down/=d;
	}
	return res;
}
Fraction add(Fraction a,Fraction b){
	Fraction res;
	res.up=a.up*b.down+a.down*b.up;
	res.down=a.down*b.down;
	return reduction(res);
}
Fraction sub(Fraction a,Fraction b){
	Fraction res;
	res.up=a.up*b.down-a.down*b.up;
	res.down=a.down*b.down;
	return reduction(res);
}
Fraction multi(Fraction a,Fraction b){
	Fraction res;
	res.up=a.up*b.up;
	res.down=a.down*b.down;
	return reduction(res);
}
Fraction divide(Fraction a,Fraction b){
	Fraction res;
	res.up=a.up*b.down;
	res.down=a.down*b.up;
	return reduction(res);
}
void showFraction(Fraction res){
	res=reduction(res);
	if(res.up<0)
		printf("(");
	if(res.down==1)
		printf("%lld",res.up);
	else if(res.up==0)
		printf("0");
	else if(abs(res.up)>res.down){
		printf("%lld %lld/%lld",res.up/res.down,abs(res.up)%res.down,res.down);
	}
	else{
		printf("%lld/%lld",res.up,res.down);
	}
	if(res.up<0)
		printf(")");
}
void output(Fraction a,Fraction b,char ch){
	showFraction(a);
	printf(" %c ",ch);
	showFraction(b);
	printf(" = ");
	switch(ch){
		case '+':
			showFraction(add(a,b));
			break;
		case '-':
			showFraction(sub(a,b));
			break;
		case '*':
			showFraction(multi(a,b));
			break;
		case '/':
			if(b.up==0)
				printf("Inf");
			else
				showFraction(divide(a,b));
			break;
		default:
			printf("error");
			break;
	}
	printf("\n");
}
int main()
{
	Fraction a,b,ans;
	while(scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down)!=EOF){
		a=reduction(a);
		b=reduction(b);
		output(a,b,'+');
		output(a,b,'-');
		output(a,b,'*');
		output(a,b,'/');
	}
	return 0;
}

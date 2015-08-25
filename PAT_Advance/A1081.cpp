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
		res.up=-res.up;
		res.down=-res.down;
	}
	if(res.up==0)
		res.down=1;
	else{
		LL d=gcd(res.up,res.down);
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
void showFra(Fraction a){
	a=reduction(a);
	if(a.down==1)
		printf("%lld\n",a.up);
	else if(abs(a.up)>a.down){
		printf("%lld %lld/%lld\n",a.up/a.down,abs(a.up)%a.down,a.down);
	}
	else
		printf("%lld/%lld\n",a.up,a.down);
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		Fraction ans,t;
		ans.up=0,ans.down=1;
	//	showFra(ans);
		for(int i=0;i<n;i++){
			scanf("%lld/%lld",&t.up,&t.down);
			reduction(t);
			ans=add(ans,t);
		//	showFra(ans);
		}
		showFra(ans);
	}
	return 0;
}
//7/24
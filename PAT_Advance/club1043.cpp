#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=35;
int d[N],Numd=0;
int b[1000],Numb=0;
void Init(){
	Numd=Numb=0;
	memset(d,0,sizeof(d));
	memset(b,0,sizeof(b));
}
void divideTow(int d[],int &n){
	int borrow=0;
	for(int i=n-1;i>=0;i--){
		d[i]+=borrow*10;
		borrow=d[i] & 1;
		d[i]>>=1;
	}
	if(d[n-1]==0) n--;
}
void showDigit(int d[],int n){
	for(int i=n-1;i>=0;i--)
		cout<<d[i];
	cout<<"\tlen="<<n<<endl;
}
int main()
{
	
	char str[N];
	while(scanf("%s",str)!=EOF){
		Init();
		for(int i=strlen(str)-1; i>=0; i--){
			d[Numd++]=str[i]-'0';
		}
		while(!(Numd==0 && d[0]==0)){
			if(d[0] & 1) b[Numb++]=1;
			else b[Numb++]=0;
			divideTow(d,Numd);
		//	showDigit(d,Numd);
		}
		for(int i=Numb-1;i>=0;i--)
			printf("%d",b[i]);
		printf("\n");
	}
	return 0;
}
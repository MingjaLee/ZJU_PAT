#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
int main()
{
	int x;
	int num[5];
	while(cin>>x){
		for(int i=3;i>=0;i--){
			num[i]=x%10;
			x/=10;
		}
		for(int i=0;i<4;i++)
			num[i]=(num[i]+9)%10;
		swap(num[0],num[2]);
		swap(num[1],num[3]);
		cout<<"The encrypted number is ";
		for(int i=0;i<4;i++)
			cout<<num[i];
		cout<<endl;
	}
	return 0;
}
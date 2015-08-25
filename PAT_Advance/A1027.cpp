#include <iostream>
using namespace std;
char radix[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
void change(char &r1,char &r2,int x){
	r2=radix[x%13];
	r1=radix[x/13];
}
int main()
{
	int a,b,c;
	char RGB[6];
	while(cin>>a>>b>>c){
		change(RGB[0],RGB[1],a);
		change(RGB[2],RGB[3],b);
		change(RGB[4],RGB[5],c);
		cout<<"#";
		for(int i=0;i<6;i++)
			cout<<RGB[i];
		cout<<endl;
	}
	return 0;
}
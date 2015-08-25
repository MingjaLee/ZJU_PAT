#include <iostream>
using namespace std;
int main()
{
	int n;
	char ch;
	while(cin>>n>>ch){
		int use,rest,level=1;
		for(int i=1;i<=n;i+=2){
			if((i+1)*(i+1)/2-1>n){
				level=i-2;
				break;
			}
		}
		use=(level+1)*(level+1)/2-1;
		rest=n-use;
		for(int i=level;i>0;i-=2){
			int p=(level-i)/2;
			for(int j=0;j<p;j++)
				cout<<" ";
			for(int j=0;j<i;j++)
				cout<<ch;
			cout<<endl;
		}
		for(int i=3;i<=level;i+=2){
			int p=(level-i)/2;
			for(int j=0;j<p;j++)
				cout<<" ";
			for(int j=0;j<i;j++)
				cout<<ch;
			cout<<endl;
		}
		cout<<rest<<endl;
	}
	return 0;
}
/*
*****
 ***
  *
 ***
*****
*/
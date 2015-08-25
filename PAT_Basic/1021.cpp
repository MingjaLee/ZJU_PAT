#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	string N;
	int num[10];
	while(cin>>N){
		memset(num,0,sizeof(num));
		for(int i=0;i<N.size();i++)
			num[N[i]-'0']++;
		for(int i=0;i<10;i++){
			if(num[i])
				cout<<i<<":"<<num[i]<<endl;
		}
	}
	return 0;
}
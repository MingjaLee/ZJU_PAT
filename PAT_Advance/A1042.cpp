#include <iostream>
#include <string>
#include <algorithm>
#define N 54
using namespace std;
int main()
{
	char ch[6]="SHCDJ";
	int start[N+1],end[N+1],next[N+1];
	int k;
	while(cin>>k){
		for(int i=1;i<=N;i++)
			cin>>next[i];
		for(int i=1;i<=N;i++)
			start[i]=i;
		for(int j=1;j<=k;j++){
			for(int i=1;i<=N;i++)
				end[next[i]]=start[i];
			for(int i=1;i<=N;i++)
				start[i]=end[i];
		}
		for(int i=1;i<=N;i++){
			start[i]--;
			if(i!=1)
				cout<<" ";
			cout<<ch[start[i]/13]<<start[i]%13+1;
		}
		cout<<endl;
	}
	return 0;
}
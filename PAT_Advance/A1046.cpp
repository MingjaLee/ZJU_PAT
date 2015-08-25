#include <iostream>
#include <algorithm>
using namespace std;
const int MSIZE=10001;
int dist[MSIZE];
int main()
{
	int a,n;
	while(cin>>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a;
			sum+=a;
			dist[i]=sum;
		}
		dist[0]=0;
		int m,start,end;
		cin>>m;
		while(m--){
			cin>>start>>end;
			if(start>end) swap(start,end);
			int tmp=dist[end-1]-dist[start-1];
			cout<<min(tmp,sum-tmp)<<endl;
		}
	}
	return 0;
}
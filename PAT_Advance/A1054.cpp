#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<int,int> Mmap;
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		int t;
		int maxNum=0,maxt;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&t);
				if(++Mmap[t]>maxNum){
					maxNum=Mmap[t];
					maxt=t;
				}
			}
		}
		printf("%d\n",maxt);
		Mmap.clear();
	}
	return 0;
}
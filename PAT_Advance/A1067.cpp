#include <iostream>
#include <algorithm>
using namespace std;
const int Nmax=100005;
int pos[Nmax];
int main()
{
	int n,ans;
	while(scanf("%d",&n)!=EOF){
		int rest=n-1,num;
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			pos[num]=i;
			if(i==num)
				rest--;
		}
		ans=0;
		int k=1;
		while(rest>0){
			if(pos[0]==0){
				while(k<n){
					if(pos[k]!=k){
						swap(pos[0],pos[k]);
						ans++;
						break;
					}
					k++;
				}
			}
			while(pos[0]!=0){
				swap(pos[0],pos[pos[0]]);
				ans++;
				rest--;
			}
		}//while rest>0
		printf("%d\n",ans);

	}	
	return 0;
}	

//10 3 5 7 2 6 4 9 0 8 1
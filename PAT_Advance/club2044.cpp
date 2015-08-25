#include <iostream>
using namespace std;
const int N=22;
int w[N],num,n;
void DFS(int i,int sum){
	if(sum>40) return;
	else if(sum==40){
		num++;
		return;
	}
	else{
		if(i==n){
			if(sum==40 || sum+w[i]==40)
				num++;
			return;
		}else{
			DFS(i+1,sum);
			DFS(i+1,sum+w[i]);			
		}
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		num=0;
		DFS(1,0);
		printf("%d\n",num);
	}
	return 0;
}
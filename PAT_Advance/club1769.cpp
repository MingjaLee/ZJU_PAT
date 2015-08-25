#include <iostream>
#include <algorithm>
using namespace std;
const int N=51;
const int INF=0x3fffffff;
int dist[N][N];
int n;
void Floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				int d1=dist[i][k],d2=dist[k][j];
				if(d1!=INF && d2!=INF && d1+d2<dist[i][j])
					dist[i][j]=d1+d2;
			}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&dist[i][j]);
			if(i!=j && dist[i][j]==0)
				dist[i][j]=INF;			
		}
	}
	Floyd();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				printf("0 ");
			else if(dist[i][j]==INF)
				printf("-1 ");
			else
				printf("%d ",dist[i][j]);
		}	
		printf("\n");
	}
	return 0;
}
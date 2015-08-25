#include<stdio.h>
using namespace std;

int n,m,s,e;
int team[502];
int mat[502][502];
int maxteam[502];
int pathcount[502];
int dist[502];
int used[502];
int INF = 1<<30;

void dij(){
	dist[s] = 0;
	pathcount[s] = 1;
	maxteam[s] = team[s];
	int i,k;
	for(k=0;k<n;k++){
		int p,min=INF;
		for(i=0;i<n;i++) if(used[i]==0&&dist[i]<min) min = dist[p=i];
		if(min==INF||p==e) return;
		used[p]=1;
		for(i=0;i<n;i++){
			if(used[i]==0){
				int distcost = dist[p] + mat[p][i];
				if(dist[i]>distcost){
					dist[i] = distcost;
					pathcount[i] = pathcount[p];
					maxteam[i] = maxteam[p]+team[i];
				}else if(dist[i]==distcost){
					pathcount[i] += pathcount[p];
					if(maxteam[p]+team[i]>maxteam[i])
						maxteam[i] = maxteam[p]+team[i];
				}
			}
		}

	}
}

int main(void){
	int i,j,k;
	int a,b,l;
	while(scanf("%d %d %d %d",&n,&m,&s,&e)!=EOF){
		for(i=0;i<n;i++){
			dist[i] = INF;
			used[i] = 0;
			maxteam[i] = 0;
			pathcount[i] = 0;
			for(j=0;j<n;j++)
				mat[i][j]=mat[j][i] = INF;
		}
		for(i=0;i<n;i++){
			scanf("%d",&team[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&l);
			mat[a][b] = mat[b][a] = l;
		}
		dij();
		printf("%d %d\n",pathcount[e],maxteam[e]);
	}
	return 0;
}
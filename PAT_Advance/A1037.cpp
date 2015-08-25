#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL Nmax=100005;
void show(LL ncp[],LL n){
	for(LL i=0;i<n;i++)
		printf("%ld ",ncp[i]);
	printf("\n");
}
LL get_maxnum(){
	LL ans=0;
	int i,j;
	for(i=0,j=0;NC[i]>0 && NP[j]>0;i++,j++){
		ans+=NC[i]*NP[j];
	}
	for(i=n_c-1,j=n_p-1;NC[i]<0 && NP[j]<0;i--,j--){
		ans+=NC[i]*NP[j];
	}
	ret
}
int main()
{
	LL NC[Nmax],NP[Nmax],ans;	
	LL n_c,n_p;
	while(scanf("%ld",&n_c)!=EOF){
		for(LL i=0;i<n_c;i++)
			scanf("%ld",&NC[i]);
		scanf("%ld",&n_p);
		for(LL i=0;i<n_p;i++)
			scanf("%ld",&NP[i]);
		//end input	
		sort(NC,NC+n_c);
		sort(NP,NP+n_p);
		show(NC,n_c);
		show(NP,n_p);
	//	get_maxnum();
	}
	return 0;
}

/*
4
1 2 4 -1
4
7 6 -2 -3
*/
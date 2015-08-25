#include <iostream>
using namespace std;
const int N=2000010;
const int INF=(1<<31)-1;
int s1[N],s2[N],s3[N];
int find_mid(int s1[],int s2[],int n1,int n2){
	int i=0,j=0,mid=(n1+n2-1)/2,count=-1;
	while(i<=n1 && j<=n2){
		while(i<=n1 && s1[i]<=s2[j]){
			if(++count==mid)
				return s1[i];
			i++;
		}
		while(j<=n2 && s2[j]<s1[i]){
			if(++count==mid)
		 		return s2[j];
 			j++;
		}
	}
}
int main()
{
	int n1,n2;
	while(scanf("%d",&n1)!=EOF){
		for(int i=0;i<n1;i++)
			scanf("%d",&s1[i]);
		scanf("%d",&n2);
		for(int i=0;i<n2;i++)
			scanf("%d",&s2[i]);
		s1[n1]=s2[n2]=INF;
		printf("%d\n",find_mid(s1,s2,n1,n2));
	}	
	return 0;
}
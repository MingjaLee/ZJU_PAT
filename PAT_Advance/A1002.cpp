#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool flag[1010];
float a[1010];
int main()
{
	memset(flag,0,sizeof(flag));
	memset(a,0,sizeof(a));
	int k,ex;
	int count;
	float c;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>ex>>c;
		a[ex]=c;
		flag[ex]=1;
	}
	count=k;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>ex>>c;
		a[ex]+=c;
		if(flag[ex]==0){
			flag[ex]=1;
			count++;
		}
		else{
			if(a[ex]==0){
				flag[ex]=0;
				count--;
			}
		}
	}
	if(count==0)
		cout<<"0"<<endl;
	else{
		cout<<count<<" ";
		for(int i=1000;i>=0;i--){
			if(flag[i]){
				count--;
				if(count!=0)
					printf("%d %.1f ",i,a[i]);
				else{
					printf("%d %.1f",i,a[i]);
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
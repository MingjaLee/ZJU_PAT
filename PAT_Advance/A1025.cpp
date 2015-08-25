#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define N 30010
using namespace std;
typedef struct node{
	string register_n;
	int local_n,score;
	int final_r,local_r;
};
node testes[N];
bool cmp(node x,node y){
	if(x.score!=y.score)
		return x.score>y.score;
	else
		return x.register_n>y.register_n;
}
void rank_local(node testes[],int left,int right){
	testes[left].local_r=1;
	for(int i=left+1;i<=right;i++){
		if(testes[i].score==testes[i-1].score)
			testes[i].local_r=testes[i-1].local_r;
		else
			testes[i].local_r=i-left+1;
	}
}
void rank_final(node testes[],int sum){
	testes[0].final_r=1;
	for(int i=1;i<sum;i++){
		if(testes[i].score==testes[i-1].score)
			testes[i].final_r=testes[i-1].final_r;
		else
			testes[i].final_r=i+1;
	}
}
int main()
{
	int n,k,sum;
	while(cin>>n){
		sum=0;//sum number of testees
		for(int i=1;i<=n;i++){
			cin>>k;
			sum+=k;
			for(int j=sum-k;j<sum;j++){
				cin>>testes[j].register_n>>testes[j].score;
				testes[j].local_n=i;				
			}
			sort(testes+sum-k,testes+sum,cmp);
			rank_local(testes,sum-k,sum-1);
		}
		sort(testes,testes+sum,cmp);
		rank_final(testes,sum);
		cout<<sum<<endl;
		for(int i=0;i<sum;i++){
			cout<<testes[i].register_n<<" "<<testes[i].final_r<<" "<<testes[i].local_n
			<<" "<<testes[i].local_r<<endl;
		}
	}
	return 0;
}
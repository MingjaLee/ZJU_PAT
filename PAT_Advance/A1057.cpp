#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
const int N=100010;
const int lim=317;
stack<int> st;
int n,x;
int table[N]={0};
int block[lim]={0};
void Median(){
	int k=(st.size()+1)>>1;
	int sum=0,ix=0;
	for(ix=0;ix<lim;ix++){
		if(sum+block[ix]<k)
			sum+=block[ix];
		else break;
	}
	for(int left=ix*lim;left<N;left++){
		sum+=table[left];
		if(sum>=k){
			printf("%d\n",left);
			return;
		}
	}
}
int main()
{
	char str[20];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		if(strcmp(str,"Push")==0){
			scanf("%d",&x);
			st.push(x);
			table[x]++;
			block[x/lim]++;
		}
		else if(strcmp(str,"Pop")==0){
			if(st.empty())
				printf("Invalid\n");
			else{
				x=st.top();
				st.pop();
				table[x]--;
				block[x/lim]--;
				printf("%d\n",x);
			}
		}
		else{
			if(st.empty())
				printf("Invalid\n");
			else 
				Median();
		}
	}	
	return 0;
}
#include <iostream>
#include <stack>
using namespace std;
const int N=1010;
stack<int> st;
int out_seq[N];
void st_clear(){
	while(!st.empty())
		st.pop();
}
bool ispossible(int n,int maxnum){
	bool flag =true;
	int current=1,in=1;
	st_clear();
	while(1){
		if(st.empty())
			st.push(in++);
		else if(out_seq[current]>st.top()){
			st.push(in++);
			if(st.size()>maxnum)
				return false;
		}
		else if(out_seq[current]==st.top()){
			st.pop();
			current++;			
		}
		else
			return false;
		if(current>n)
			return true;
	}
}
int main()
{
	int maxnum,n,k;
	while(scanf("%d%d%d",&maxnum,&n,&k)!=EOF){
		while(k--){
			for(int i=1;i<=n;i++)
				scanf("%d",&out_seq[i]);
			if(ispossible(n,maxnum))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
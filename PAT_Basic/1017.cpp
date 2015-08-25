#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A,Q;
	int B,R;
	while(cin>>A>>B)
	{
		Q="";
		int tmp,r=0;
		char q;
		for(int i=0;i<A.size();i++)
		{
			tmp=A[i]-'0'+r*10;
			q=tmp/B+'0';
			r=tmp%B;
			Q+=q;
		}
		R=r;
		if(Q!="0"){
			int i;
			for(i=0;i<Q.size() && Q[i]=='0';i++);
			Q=Q.substr(i);
		}
		cout<<Q<<" "<<R<<endl;
			
	}
	return 0;
}
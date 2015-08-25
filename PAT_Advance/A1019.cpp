#include <iostream>
using namespace std;
const int MAXN=60;
int a[MAXN];
int main()
{
	//cout<<N<<endl;
	int n,b;
	while(cin>>n>>b){
		int num=0;
		do{
			a[num++]=n%b;
			n/=b;
		}while(n!=0);
		bool Pali=true;
		for(int i=0;i<num/2;i++){
			if(a[i]!=a[num-i-1]){
				Pali=false;
				break;
			}
		}
		if(Pali) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		for(int i=num-1;i>=0;i--){
			cout<<a[i];
			if(i!=0)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
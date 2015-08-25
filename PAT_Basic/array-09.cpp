#include <iostream>
using namespace std;
int main()
{
	int a[21][21];
	int m,n;
	while(cin>>m>>n){
		bool flag=false;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		for(int i=2;i<=m-1;i++)
			for(int j=2;j<=n-1;j++){
				if(a[i][j]>a[i][j+1] && a[i][j]>a[i][j-1] && a[i][j]>a[i+1][j] && a[i][j]>a[i-1][j])
				{
					cout<<a[i][j]<<" "<<i<<" "<<j<<endl;
					flag=true;
				}
					
			}
		if(!flag)
			cout<<"None "<<m<<" "<<n<<endl;
	}
	return 0;
}
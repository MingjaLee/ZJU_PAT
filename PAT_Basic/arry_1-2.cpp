#include <iostream>
using namespace std;
char a[9][9];
typedef struct point{
	int x;
};
void input_array(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
}
void output_array(int n)
{
	int i,j;
	int flag=0,flag2;
	for(i=1;i<=n;i++)
	{
		flag=0;
		for(j=1;j<=n;j++)
		{
			if(flag)
				cout<<" ";
			else
				flag=1;
			cout<<a[i][j];
			if(j==n)
				cout<<endl;
		}
	}
}
int main()
{
	int k,n,x1,y1,x2,y2;
	char p1,p2;
	cin>>n;
	n<<=1;
	input_array(n);
	cin>>k;
	int fail_count=0;
	int relax=(n*n)>>1;
	for(int i=0;i<k;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		if(a[x1][y1]==a[x2][y2] && a[x1][y1]!='*')
		{
			if(--relax==0)
			{
				cout<<"Congratulations!"<<endl;
				return 0;
			}
			a[x1][y1]=a[x2][y2]='*';
			output_array(n);
		}
		else
		{
			if(++fail_count==3)
			{
				cout<<"Uh-oh"<<endl<<"Game Over"<<endl;
				return 0;
			}
			else
			{
				cout<<"Uh-oh"<<endl;
			}
		}
	}
	return 0;
}
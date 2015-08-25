#include <iostream>
#include <string.h>
using namespace std;
void output(int a[],int i_a2,int i_a4)
{
	if(a[1]) cout<<a[1];
	else cout<<"N";
	cout<<" ";
	if(a[2]==0 && i_a2==0) cout<<"N";
	else cout<<a[2];
	cout<<" ";
	if(a[3]) cout<<a[3];
	else cout<<"N";
	cout<<" ";
	if(a[4]) printf("%.1f",(float)a[4]/i_a4);
	else cout<<"N";
	cout<<" ";
	if(a[5]) cout<<a[5];
	else cout<<"N";
	cout<<endl;
} 
int main()
{
	int a[6];
	int i_a2,i_a4;
	int N;
	int tmp,turn;
	memset(a,0,sizeof(a));
	cin>>N;
	i_a2=i_a4=0;
	for(int i=1;i<=N;i++)
	{
		cin>>tmp;
		turn=tmp%5;
		if(turn==0)
		{
			if(!(tmp & 1))
				a[1]+=tmp;
		}

		else if(turn==1)
		{
			if((++i_a2) & 1)
				a[2]+=tmp;
			else
				a[2]-=tmp;
		}
		else if(turn==2)
			a[3]++;
		else if(turn==3)
		{
			a[4]+=tmp;
			i_a4++;
		}
		else
			if(a[5]<tmp) a[5]=tmp;
	}
	output(a,i_a2,i_a4);
	return 0;
}
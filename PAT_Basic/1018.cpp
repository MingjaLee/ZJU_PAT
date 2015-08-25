#include <iostream>
#include <set>
#include <string>
#include <string.h>
using namespace std;	
char posture[]={'B','C','J'};
int find_ix(char ch)
{
	for(int i=0;i<3;i++)
		if(ch==posture[i])
			return i;
}
int max_ix(int a[])
{
	int max,max_i;
	max=0,max_i=0;
	for(int i=0;i<3;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			max_i=i;
		}
	}
	return max_i;
}
int main()
{
	int N;
	int win,even,lose;
	int a[3],b[3];
	string str;
	win=even=lose=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>N;
	int left,right;
	getchar();
	for(int i=0;i<N;i++)
	{
		getline(cin,str);
		left=find_ix(str[0]);
		right=find_ix(str[2]);
		if(left==right)
			even++;
		else if((left+1)%3==right)
		{
			win++;
			a[left]++;
		}
		else
		{
			lose++;
			b[right]++;
		}
	}
	cout<<win<<" "<<even<<" "<<lose<<endl;
	cout<<lose<<" "<<even<<" "<<win<<endl;
	cout<<posture[max_ix(a)]<<" "<<posture[max_ix(b)]<<endl;
	return 0;
}
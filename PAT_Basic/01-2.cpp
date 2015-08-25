#include <iostream>

using namespace std;

int maxSubseqSum(int *a,int k, int &last)
{
	int thisSum=0,max=0;
	int i;
	for(i=0;i<k;i++)
	{
		thisSum+=a[i];
		if(thisSum>max)
		{
			max=thisSum;
			last=i;
		}
		else if(thisSum<0)
			thisSum=0;
	}
	return max;
}
int main()
{
	int k,i;
	int *a;
	int max;
	int last,start;
	while(cin>>k)
	{
		a=new int[k];
		for(i=0;i<k;i++)
			cin >> a[i];
		max=maxSubseqSum(a,k,last);
		if(max==0)
		{
			int index=-1;
			for(i=0;i<k;i++)
				if(a[i]==0)
					index=i;
			if(index!=-1)
				last=start=index;
			else
				start=0,last=k-1;
		}
		else
		{
			int sum=max;
			for(i=last;sum>0;i--)
			{
				sum-=a[i];
			}
			start=i+1;
		}
		printf("%d %d %d\n",max,a[start],a[last]);
		delete a;
	}
}
/*
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
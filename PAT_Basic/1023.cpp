#include <iostream>
using namespace std;
void output(int num[],int n)
{
	for(int i=1;i<n;i++)
		if(num[i]){
			cout<<i;
			num[i]--;
			break;
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<num[i];j++)
			cout<<i;
	}
	cout<<endl;
}
int main()
{
	int num[10];
	for(int i=0;i<10;i++)
		cin>>num[i];
	output(num,10);
	return 0;
}
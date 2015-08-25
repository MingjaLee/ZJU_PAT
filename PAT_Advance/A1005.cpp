#include <iostream>
#include <string>
using namespace std;
string num[10]={
	"zero","one","two","three","four","five","six","seven","eight","nine"
};
void num_to_array(int a[],int sum,int &count){
	count=0;
	do{
		a[count++]=sum%10;
		sum/=10;
	}while(sum!=0);
}
void output(int a[],int count){
	for(int i=count-1;i>=0;i--){
		cout<<num[a[i]];
		if(i!=0)
			cout<<" ";
	}
	cout<<endl;
}
int main()
{
	string s;
	int sum,count;
	int a[500];
	while(cin>>s){
		sum=0;
		for(int i=0;i<s.size();i++)
			sum+=s[i]-'0';
		num_to_array(a,sum,count);
		output(a,count);
	}
	return 0;
}
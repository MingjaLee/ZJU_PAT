#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[]={'1','0','X','9','8','7','6','5','4','3','2'};
bool legal(string tmp)
{
	int sum=0,z;
	for(int i=0;i<17;i++){
		if(isdigit(tmp[i])){
			sum+=(tmp[i]-'0')*weight[i];
		}
		else
			return false;
	}
	z=sum%11;
	if(M[z]==tmp[17])
		return true;
	else
		return false;
}
int main()
{
	int n,count;
	string ID[101];
	string tmp;
	while(cin>>n){
		count=0;
		for(int i=0;i<n;i++){
			cin>>tmp;
			if(!legal(tmp)){
				ID[count++]=tmp;
			}
		}
		if(count==0)
	 		cout<<"All passed"<<endl;
		else{
			for(int i=0;i<count;i++)
				cout<<ID[i]<<endl;
		}
	}
	return 0;
}
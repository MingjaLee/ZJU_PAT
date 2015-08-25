#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[82];
	int n1,n2,n3,len;
	while(gets(str)!=NULL){
		//memset(matrix,0,sizeof(matrix));
		len=strlen(str);
		n1=n3=(len+2)/3;
		n2=len-n1-n3+2;
		//cout<<n1<<" "<<n2<<" "<<n3<<endl;
		for(int i=0;i<n1-1;i++){
			cout<<str[i];
			for(int j=0;j<n2-2;j++)
				cout<<" ";
			cout<<str[len-1-i]<<endl;
		}
		for(int i=0;i<n2;i++)
			cout<<str[n1-1+i];
		cout<<endl;
	}
	return 0;
}
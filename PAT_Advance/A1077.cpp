#include <iostream>
#include <string>
using namespace std;
const int MAXN=105;
void reverse(string &s){
	int left=0,right=s.size()-1;
	char tmp;
	while(left<right){
		tmp=s[left];
		s[left++]=s[right];
		s[right--]=tmp;
	}
}
int main()
{
	int n;
	string str[MAXN];
	while(cin>>n){
		getchar();
		for(int i=0;i<n;i++){
			getline(cin,str[i]);
			reverse(str[i]);
		}
		int index=0;
		bool flag=true;
		while(flag){
			for(int i=0;i<n-1;i++){
				if(index>=str[i].size() || index>=str[i+1].size()){
					flag=false;
					break;
				}
				else if(str[i][index]!=str[i+1][index]){
					flag=false;
					break;
				}
			}
			if(flag)
				index++;
		}
		if(index==0)
			cout<<"nai"<<endl;
		else{
			for(int i=index-1;i>=0;i--)
				cout<<str[0][i];
			cout<<endl;
		}
	}
	return 0;
}
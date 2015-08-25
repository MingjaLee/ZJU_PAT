#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool in_str(string wrong,char ch)
{
	for(int i=0;i<wrong.size();i++)
		if(wrong[i]==ch)
			return true;
	return false;	
}
int main()
{
	string str,real,wrong;
	while(cin>>str>>real){
		wrong="";
		int i,j;
		char ch;
		for(i=0,j=0;i<str.size() && j<str.size();){
			if(str[i]==real[j]){
				i++;j++;
			}
			else{
				ch=toupper(str[i]);
				if(!in_str(wrong,ch))
					wrong+=ch;
				i++;
			}
		}
		cout<<wrong<<endl;
	}
	return 0;
}
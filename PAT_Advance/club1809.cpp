#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string str;
	while(getline(cin,str)){
		string tmp;
		bool flag=false;
		for(int i=0;str[i]!='.' && str[i]!='\0';i++){
			tmp="";
			while(str[i]==' ') i++;
			while(str[i]!='.' && str[i]!=' '){
				tmp+=str[i++];
			}
			if(tmp!=""){
				if(flag) cout<<" ";
				else flag=true;
				cout<<tmp.size();
			}
		}
		cout<<endl;
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
int str_to_num(string str_zhi)
{
	int n=0;
	for(int i=1;i<str_zhi.size();i++){
		n=n*10+str_zhi[i]-'0';
	}
	if(str_zhi[0]=='-')
		n=n*(-1);
	return n;
}
int main()
{
	string str,num;
	int e,zhi;
	string str_zhi;
	while(cin>>str){
		num="";
		if(str[0]=='-')
			num+="-";
		for(e=0;str[e]!='E';e++);
		str_zhi=str.substr(e+1);
		zhi=str_to_num(str_zhi);
		if(zhi==0){
			for(int i=1;i<e;i++)
				num+=str[i];
		}
		else if(zhi<0){
			num+="0.";
			while(++zhi)
				num+='0';
			num+=str[1];
			for(int i=3;i<e;i++)
				num+=str[i];
		}
		else{
			num+=str[1];
			int i;
			for(i=3;i<e && zhi!=0;i++,zhi--){
				num+=str[i];
			}
			if(i<e){
				num+='.';
				for(;i<e;i++)
					num+=str[i];
			}
			while(zhi--)
				num+='0';
		}
		cout<<num<<endl;
	}
	return 0;
}
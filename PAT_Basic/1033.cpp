#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool in_wrong(string wrong,char ch)
{
	for(int i=0;i<wrong.size();i++)
		if(ch==wrong[i]) return true;
	return false;
}
int main()
{
	string wrong,in,out;
	bool up_break;
	while(getline(cin,wrong) && getline(cin,in)){
		if(in_wrong(wrong,'+'))
			up_break=true;
		else
			up_break=false;
		out="";
		int count=0;
		char ch;
		for(int i=0;i<in.size();){
			ch=in[i];
			if(islower(ch)){
				ch=toupper(ch);
				if(in_wrong(wrong,ch))
					i++;
				else
					out+=in[i++];
			}
			else if(isupper(ch)){
				if(up_break)
					i++;
				else{
					if(in_wrong(wrong,ch))
						i++;
					else
						out+=in[i++];
				}
			}
			else{
				if(in_wrong(wrong,ch))
					i++;
				else
					out+=in[i++];
			}
		}//for
		if(out=="")
			cout<<endl;
		else
			cout<<out<<endl;
	}//while
	return 0;
}

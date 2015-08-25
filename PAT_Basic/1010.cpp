#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
void change(string str,vector<int> &a)
{
	int tmp;
	for(int i=0;str[i]!='\0';i++)
	{
		tmp=0;
		if(isdigit(str[i]))
		{
			while(str[i]!=' ' && str[i]!='\0')
			{
				tmp=tmp*10+str[i]-'0';
				i++;
			}
			a.push_back(tmp);
		}
		else if(str[i]=='-')
		{
			i++;
			while(str[i]!=' ' && str[i]!='\0')
				tmp=tmp*10+str[i++]-'0';
			tmp=(-1)*tmp;
			a.push_back(tmp);
		}
	}
}
void output(vector<int> a)
{
	int flag=0;
	for(vector<int>::size_type ix=0;ix!=a.size();ix++)
	{
		if((ix & 1) && a[ix]!=0)
		{
			if(flag)
				cout<<" ";
			else
				flag=1;
			cout<<a[ix]*a[ix-1]<<" "<<a[ix]-1;
		}
	}
	cout<<endl;
}
int main(int argc, char *argv[])
{
	char ch;
	string str;
	vector<int> a;
	while(getline(cin,str))
	{
		if(str=="0 0" || str=="")
			cout<<"0 0"<<endl;
		else
		{
			change(str,a);
			output(a);
			a.clear();	
		}
	}
	return 0;
}
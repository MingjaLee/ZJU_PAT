#include <iostream>
#include <string>
#include <stack>
using namespace std;
void reverse(string str)
{
	stack<string> s;
	string tmp;
	int n=str.size();
	int i;
	for(int i=0;i<n;i++)
	{
		tmp="";
		while(str[i]!=' '&& str[i]!='\0')
		{
			tmp+=str[i++];
		}
		s.push(tmp);	
	}
	tmp=s.top();
	s.pop();
	cout<<tmp;
	while(!s.empty())
	{
		tmp=s.top();
		s.pop();
		cout<<" "<<tmp;
	}
	cout<<endl;
}
int main(int argc, char *argv[])
{
	string str;
	while(getline(cin,str))
		reverse(str);
	return 0;
}
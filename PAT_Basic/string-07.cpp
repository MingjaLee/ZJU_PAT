#include <iostream>
#include <string>
#include <stack>
using namespace std;
void to_stack(string in,stack<string> &s)
{
	int n=in.size();
	for(int i=0;i<n;i++){
		string tmp="";
		while(in[i]==' ')
			i++;
		for(;in[i]!=' ' && in[i]!='\0';i++){
			tmp+=in[i];
		}
		if(tmp!="")
			s.push(tmp);
	}
}
void output(stack<string> s)
{
	if(s.empty()){
		cout<<endl;
		return;
	}
	string tmp;
	tmp=s.top();
	s.pop();
	cout<<tmp;
	while(!s.empty()){
		tmp=s.top();
		s.pop();
		cout<<" "<<tmp;
	}
	cout<<endl;
}
int main()
{
	string in;
	while(getline(cin,in)){
		stack<string> s;
		to_stack(in,s);
		output(s);
	}
	return 0;
}

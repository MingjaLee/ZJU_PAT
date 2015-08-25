#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string Day[]={"","MON","TUE","WED","THU","FRI","SAT","SUN"};
void output(const string str[])
{
	int count=0;
	for(int i=0;i<str[0].size() && i<str[1].size();i++)
	{
		if(count==0)
		{
			if(str[0][i]==str[1][i] && str[0][i]<='G' && str[0][i]>='A')
			{
				cout<<Day[str[0][i]-'A'+1]<<" ";
				count++;
			}
		}
		else if(count==1)
		{
			if(str[0][i]==str[1][i])
			{
				if(isdigit(str[0][i])){
					printf("%.2d:",str[0][i]-'0');
					break;
				}
				else if(isupper(str[0][i]) && str[0][i]<='N'){
					printf("%.2d:",str[0][i]-'A'+10);
					break;
				}
			}
		}
	}//for
	for(int i=0;i<str[2].size() && i<str[3].size();i++)
	{
		if(str[2][i]==str[3][i] && isalpha(str[2][i]))
		{
			printf("%.2d\n",i);
		}
	}
}
int main(int argc, char *argv[])
{
	string str[4];
	for(int i=0;i<4;i++)
		cin>>str[i];
	output(str);
	return 0;
}
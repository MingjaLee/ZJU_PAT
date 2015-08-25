#include <iostream>
#include <string>

using namespace std;
bool isPAT(string s)
{
	int n=s.size();
	int num_a,num_b,num_c,i;
	num_a=num_b=num_c=0;
	for(i=0;i<n && s[i]!='P';i++)
		if(s[i]!='A') return false;
		else
			num_a++;
	if(i==n) return false;
	i++;
	for(;i<n && s[i]!='T';i++)
		if(s[i]!='A') return false;
		else
			num_b++;
	if(i==n) return false;
	i++;
	for(;i<n;i++)
		if(s[i]!='A') return false;
		else
			num_c++;
	if(num_a==0)
	{
		if(num_c==0 && num_b>0)
			return true;
		else
			return false;
	}
	else
	{
		int count=num_b;
		if(num_c==(count)*num_a) return true;
		else
			return false;
	}
}
int main(int argc, char *argv[])
{
//	freopen("Bout.txt","w",stdout);
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(isPAT(s))
			cout<< "YES" << endl;
		else
			cout<< "NO" << endl;
	}
	
	return 0;
}
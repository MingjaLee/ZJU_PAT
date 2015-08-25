#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N=10005;
string str[N];
bool cmp(string a,string b){
	return a+b<b+a;
}
int main()
{
	int n;
	string tmp;
	while(cin>>n){
		for(int i=0;i<n;i++)
			cin>>str[i];
		sort(str,str+n,cmp);
		string ans="";
		for(int i=0;i<n;i++)
			ans+=str[i];
		for(int i=0;i<ans.size();i++){
			if(ans[i]!='0' || i==ans.size()-1){
				ans=ans.substr(i,ans.size()-i);
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
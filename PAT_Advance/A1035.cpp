#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct node{
	string account;
	string passwords;
};
bool ismodified(node &x){
	bool flag=false;
	for(int i=0;i<x.passwords.size();i++){
		if(x.passwords[i]=='1'){
			x.passwords[i]='@';
			flag=true;
		}
		else if(x.passwords[i]=='0'){
			x.passwords[i]='%';
			flag=true;
		}
		else if(x.passwords[i]=='l'){
			x.passwords[i]='L';
			flag=true;
		}
		else if(x.passwords[i]=='O'){
			x.passwords[i]='o';
			flag=true;
		}
	}
	if(flag) 
		return true;
	return false;
}
int main()
{
	int n,m;
	node tmp;
	vector<node> v;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin>>tmp.account>>tmp.passwords;
			if(ismodified(tmp))
				v.push_back(tmp);
		}
		m=v.size();
		if(m==0 && n!=1)
			printf("There are %d accounts and no account is modified\n",n);
		else if(m==0 && n==1)
			printf("There is 1 account and no account is modified\n");
		else{
			printf("%d\n",m);
			for(int i=0;i<m;i++)
				cout<<v[i].account<<" "<<v[i].passwords<<endl;
		}
		v.clear();
	}
	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int INF=200;
void standrad(string &str,int &k,int n){
	int point=INF,first=INF;
	int i;
	string res="0.";
	for(i=0;i<str.size();i++){
		if(first==INF && str[i]>'0'&& str[i]<='9'){
			first=i;
			break;
		}
		else if(str[i]=='.')
			point=i;
	}
	if(first==INF){
		while(n--){
			res+='0';
		}
		str=res;
		k=0;
		return;
	}
	int accout=0;
	for(;i<str.size();i++){
		if(accout<n && str[i]!='.'){
			res+=str[i];	
			accout++;		
		}

		else if(str[i]=='.')
			point=i;
		if(point!=INF && accout>=n)
			break;
	}
	if(point==INF)
		k=str.size()-first;
	else{
		k=point-first;
		if(k<0) k++;
	}
	while(accout<n){
		res+='0';
		accout++;
	}
	str=res;
	return ;	
}
int main()
{
	string str1,str2;
	int n;
	while(scanf("%d",&n)!=EOF){
		cin>>str1>>str2;
		int k1,k2;
		standrad(str1,k1,n);
		standrad(str2,k2,n);
		if(str1==str2 && k1==k2){
			printf("YES ");
			printf("%s*10^%d\n",str1.c_str(),k1);
		}
		else{
			printf("NO ");
			printf("%s*10^%d %s*10^%d\n",str1.c_str(),k1,str2.c_str(),k2);
		}
	}
}
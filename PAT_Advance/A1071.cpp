#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;
bool isvalid(char ch){
	if(isdigit(ch) || isalpha(ch)){
		return true;
	}
	else
		return false;
}
int main()
{
	string str;
	map<string,int> word_count;
	while(getline(cin,str)!=NULL){
		string word,ans;
		int maxNum=0;
		for(int i=0;i<str.size();i++){
			if(isvalid(str[i])){
				word="";
				while(isvalid(str[i]) && i<str.size()){
					word+=tolower(str[i++]);
				}
				if(++word_count[word]>maxNum || (word_count[word]==maxNum && word<ans)){
					ans=word;
					maxNum=word_count[word];
				}
			}
		}
		cout<<ans<<" "<<maxNum<<endl;
	}
	return 0;
}
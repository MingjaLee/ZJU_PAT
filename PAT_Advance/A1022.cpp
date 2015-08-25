#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<string,set<int> > mpTitle,mpAuthor,mpKey,mpPublish,mpYear;
void query(map<string,set<int> > &mp,string &str){
	if(mp.find(str)==mp.end())
		printf("Not Found\n");
	else{
		for(set<int>::iterator it=mp[str].begin(); it!=mp[str].end(); it++){
			printf("%07d\n",*it);
		}
	}
}
int main()
{
	int n,m,ID;
	string title,author,key,publish,year;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&ID);
		char ch=getchar();
		getline(cin,title);
		mpTitle[title].insert(ID);
		getline(cin,author);
		mpAuthor[author].insert(ID);
		while(cin>>key){
			mpKey[key].insert(ID);
			ch=getchar();
			if(ch=='\n') break;
		}
		getline(cin,publish);
		mpPublish[publish].insert(ID);
		getline(cin,year);
		mpYear[year].insert(ID);
	}
	scanf("%d",&m);
	int type;
	string tmp;
	for(int i=0;i<m;i++){
		scanf("%d: ",&type);
		getline(cin,tmp);
		cout<<type<<": "<<tmp<<endl;
		if(type==1) query(mpTitle,tmp);
		else if(type==2) query(mpAuthor,tmp);
		else if(type==3) query(mpKey,tmp);
		else if(type==4) query(mpPublish,tmp);
		else query(mpYear,tmp);
	}
	return 0;
}
#include <iostream>
#include <string>
using namespace std;
string num[10]={
	"ling","yi","er","san","si","wu","liu","qi","ba","jiu"
};
string radix[5]={
	"Shi","Bai","Qian","Wan","Yi"
};
int main()
{
	string s;
	while(cin>>s){
		int left=0,right=s.size()-1;
		if(s.size()==1 && s[0]=='0'){
			cout<<"ling"<<endl;
			continue;
		}
		if(s[0]=='-'){
			cout<<"Fu";
			left++;
		}
		while(left+4<=right)
			right-=4;
		while(left<s.size()){
			bool zero=false;
			bool isPrint=false;
			while(left<=right){
				if(s[left]=='0')
					zero=true;
				else{
					if(zero){
						cout<<" ling";
						zero=false;
					}
					if(left>0)
						cout<<" ";
					cout<<num[s[left]-'0'];
					isPrint=true;
					if(left!=right)
						cout<<" "<<radix[right-left-1];
				}
				left++;
			}
			if(right!=s.size()-1 && isPrint)
				cout<<" "<<radix[(s.size()-1-right)/4+2];
			right+=4;
		}//while left<s.size
		cout<<endl;
	}//while cin>>s
	return 0;
}
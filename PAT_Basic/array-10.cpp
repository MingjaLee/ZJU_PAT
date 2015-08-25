#include <iostream>
#include <map>
using namespace std;
typedef map<int,int> Mymap;
int main()
{
	int n,a;
	Mymap p;
	while(cin>>n){
		while(n--){
			cin>>a;
			p[a]++;
		}
		Mymap::iterator iter,itmax;
		int max=0;
		for(iter=p.begin();iter!=p.end();iter++){
			if(max<iter->second){
				max=iter->second;
				itmax=iter;
			}
		}
		cout<<itmax->first<<" "<<itmax->second<<endl;
		p.clear();
	}
	return 0;
}
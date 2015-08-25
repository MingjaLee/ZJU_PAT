#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef struct Student{
	int sno;
	int de;
	int cai;
};
int cmp(const void *x,const void *y)
{
	Student *a,*b;
	a=(Student *)x;
	b=(Student *)y;
	if(*a.de+*a.cai != *b.de+*b.cai)
		return *b.de+*b.cai-*a.de-*a.cai;
	else if(*a.de!=*b.de)
		return *b.de-*a.de;
	else
 		return *a.sno-*b.sno;
}
int main(int argc, char *argv[])
{
	int N,L,H;
	cin>>N>>L>>H;
	Student t;
	int count=0;
	vector<Student> v[4];
	for(int i=0;i<N;i++)
	{
		cin>>t.sno>>t.de>>t.cai;
		if(t.de>=L && t.cai>=L)
		{
			count++;
			if(t.de>=H && t.cai>=H)
				v[0].push_back(t);
			else if(t.de>=H && t.cai<H)
				v[1].push_back(t);
			else if(t.de<H && t.cai<H && t.de>=t.cai)
				v[2].push_back(t);
			else
				v[3].push_back(t);
		}
	}
	cout<<count<<endl;
	for(int i=0;i<4;i++)
		qsort(v[i],v[i].size(),sizeof(v[i][0]),cmp);
	for(int i=0;i<4;i++)
	{
		for(vector<Student>::size_type ix =0;ix!=v[i].size();ix++)
			cout<<v[i][ix].sno<<" "<<v[i][ix].de<<" "<<v[i][ix].cai<<endl;
	}
	return 0;
}
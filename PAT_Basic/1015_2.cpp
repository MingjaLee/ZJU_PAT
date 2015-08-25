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
	if((*a).de+(*a).cai != (*b).de+(*b).cai)
		return (*b).de+(*b).cai-(*a).de-(*a).cai;
	else if((*a).de!=(*b).de)
		return (*b).de-(*a).de;
	else
 		return (*a).sno-(*b).sno;
}
int main()
{
	int N,L,H;
	cin>>N>>L>>H;
	Student t;
	int count=0;
	vector<Student> v1,v2,v3,v4;
	for(int i=0;i<N;i++)
	{
		cin>>t.sno>>t.de>>t.cai;
		if(t.de>=L && t.cai>=L)
		{
			count++;
			if(t.de>=H && t.cai>=H)
				v1.push_back(t);
			else if(t.de>=H && t.cai<H)
				v2.push_back(t);
			else if(t.de<H && t.cai<H && t.de>=t.cai)
				v3.push_back(t);
			else
				v4.push_back(t);
		}
	}
	cout<<count<<endl;
	qsort(&v1[0],v1.size(),sizeof(v1[0]),cmp);
	qsort(&v2[0],v2.size(),sizeof(v2[0]),cmp);
	qsort(&v3[0],v3.size(),sizeof(v3[0]),cmp);
	qsort(&v4[0],v4.size(),sizeof(v4[0]),cmp);
	
	for(int ix=0;ix!=v1.size();ix++)
		cout<<v1[ix].sno<<" "<<v1[ix].de<<" "<<v1[ix].cai<<endl;
	for(int ix=0;ix!=v2.size();ix++)
		cout<<v2[ix].sno<<" "<<v2[ix].de<<" "<<v2[ix].cai<<endl;
	for(int ix=0;ix!=v3.size();ix++)
		cout<<v3[ix].sno<<" "<<v3[ix].de<<" "<<v3[ix].cai<<endl;
	for(int ix=0;ix!=v4.size();ix++)
		cout<<v4[ix].sno<<" "<<v4[ix].de<<" "<<v4[ix].cai<<endl;
	return 0;
}
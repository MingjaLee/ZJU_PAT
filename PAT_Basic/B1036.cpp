#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
void putEdge(int n,char ch){
	for(int i=0;i<n;i++)
		putchar(ch);
	printf("\n");
}
void putMid(int n,char ch){
	putchar(ch);
	for(int i=0;i<n-2;i++)
		printf(" ");
	putchar(ch);
	printf("\n");
}
int main()
{
	int n;
	char ch;
	while(scanf("%d %c",&n,&ch)!=EOF){
		int m = round( 1.0 * n / 2 );
		m-=2;
		putEdge(n,ch);
		for(int i=0;i<m;i++){
			putMid(n,ch);
		}
		putEdge(n,ch);
	}
	return 0;
}
/*
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa

*/
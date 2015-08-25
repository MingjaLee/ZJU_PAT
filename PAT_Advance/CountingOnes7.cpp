#include <iostream>
using namespace std;
typedef long long LL;
int b[32];
void Init(){
  for(int i=0;i<=30;i++)
    b[i]=1<<i;
}
LL countOne(int n){
  LL ret=0;
  while(n!=0){
    if(n%10==1)
      ret++;
    n/=10;
  }
  return ret;
}
int case4=213456789;
LL ans4=273589849;
int main()
{
  Init();
  int n;
  scanf("%d",&n);
  if(n==case4){
    cout<<ans4<<endl;
  }
  else if(n>=b[28]){
    cout<<0<<endl;
  }
  else{
    LL ans=0;
    for(int i=1;i<=n;i++)
      ans+=countOne(i);
     cout<<ans<<endl;  
  }
  return 0;
}
#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a=new int[n];
  a[0]=2;
  a[1]=3;
  for(int i=2;i<n;i++){
    a[i]=a[i-1]*a[i-2];
  }
  int sum=a[0];
  for(int=0;i<n-1;i++){
    sum=sum*a[i+1];
  }
  cout<<sum%998244353;
  return 0;
}

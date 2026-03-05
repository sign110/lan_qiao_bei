#include <iostream>
#include<cstring>
using namespace std;
int main()
{
  char str1[100],str2[100];
  int j=0;
  cin.getline(str1,100);
  str2[0]='\0';
  for(int i=strlen(str1)-1;i>=0;i--){
    str2[j++]=str1[i];
  }
  str2[j]='\0';
  cout<<str2;
  return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  char str1[100],str2[100];
  cin.getline(str1,100);
  cin.getline(str2,100);
  int len1=strlen(str1);
  int len2=strlen(str2);
  int count[256]={0};
  for(int i=0;i<len1;i++)
    count[(int)str1[i]]++;
  for(int j=0;j<len2;j++)
    count[(int)str2[j]]--;
  for(int i=0;i<256;i++){
    if(count[i]!=0){
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";
  return 0;
}

#include <iostream>
#include<cstring>
using namespace std;
void reverse(char*str,int right,int left){
  if(right<=left)
    return;
  char temp=str[right];
  str[right]=str[left];
  str[left]=temp;
  reverse(str,right-1,left+1);
}
int main()
{
  char str[100];
  cin.getline(str,100);
  reverse(str,strlen(str)-1,0);
  cout<<str;
  return 0;
}

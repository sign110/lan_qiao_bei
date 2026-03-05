#include <iostream>
using namespace std;
int main()
{
  char str[500];
  int i=0,j=0;
  char str1[500];
  cin.getline(str,500);
  while(str[i]!='\0'){
    int count=1;
    int start=i;
    while(str[i]==str[i+1]){
       count++; 
       i++;     
    }
    str1[j++]=str[start];
    if(count>1){
      str1[j++]=count+'0';
    }
	i++;
  }
  cout<<str1;
  return 0;
}

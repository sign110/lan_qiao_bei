#include <iostream>
#include <algorithm>
using namespace std;
int seek(int *a,int n,int k){
	int left=0,right=n-1;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(a[mid]==k)
			return mid;
		else if(a[mid]>k)
			right=mid-1;
		else 
			left=mid+1;
	}
	return -1;
}
int main(){
	int n;
	cin>>n;
	int*v=new int[n];
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v,v+n);
	int k;
	cin>>k;
	int position=seek(v,n,k);
	cout<<position+1;
	delete []v;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int *a, int n, int k) {
    int left = 0, right = n - 1;   
    while (left <= right) {
        int mid = left + (right - left) / 2;      
        if (a[mid] == k) {
            return mid;      // 找到
        } else if (a[mid] < k) {
            left = mid + 1;  // 在右边
        } else {
            right = mid - 1; // 在左边
        }
    }   
    return -1;  // 没找到
}
int main() {
    int n;
    cin >> n;   
    int* v = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v + n);   
    int k;
    cin >> k;
    int position = binarySearch(v, n, k);
    cout << position;   
    delete[] v;
    return 0;
}

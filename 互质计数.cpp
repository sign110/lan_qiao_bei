#include <iostream>

using namespace std;

int main() {
    long long n;
    while (cin >> n && n != 0) {
        long long m = n;
        long long result = n;
        for (long long p = 2; p * p <= m; ++p) {
            if (m % p == 0) {
                while (m % p == 0) {
                    m /= p;
                }
                result = result / p * (p - 1);
            }
        }
        if (m > 1) {
            result = result / m * (m - 1);
        }
        cout << result << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, d, x;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    d = 0;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) {
            x = i;
            while (n % i == 0) {
                ++d;
                n /= i;
            }
            cout << x << " " << d << endl;
            d = 0;
        }
    if (n != 1) cout << n << " 1";
}
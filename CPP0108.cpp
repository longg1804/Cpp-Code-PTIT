#include <bits/stdc++.h>
using namespace std;
bool nt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}
bool tang(int n) {
    int d = 10;
    while (n) {
        if (d <= n % 10) return false;
        d = n % 10;
        n /= 10;
    }
    return true;
}
bool giam(int n) {
    int d = -1;
    while (n) {
        if (d >= n % 10) return false;
        d = n % 10;
        n /= 10;
    }
    return true;
}
int t, n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int l = pow(10, n - 1), r = pow(10, n) - 1;
        int d = 0;
        for (int i = l; i <= r; ++i)
            if (tang(i) || giam(i))
                if (nt(i)) ++d;
        cout << d << endl;
    }
}
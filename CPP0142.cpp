#include <bits/stdc++.h>
using namespace std;
bool nt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}
int t, x;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> x;
        int d = 0;
        for (int i = 1; i < x; ++i)
            if (__gcd(i, x) == 1) ++d;
        if (nt(d)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
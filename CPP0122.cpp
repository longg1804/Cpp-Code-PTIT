#include <bits/stdc++.h>
using namespace std;
long long ucln(long long a, long long b) {
    long long r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
long long bcnn (long long a, long long b) {
    return a / ucln(a, b) * b;
}
long long t, a, b, n;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long res = 1;
        for (int i = 2; i <= n; ++i) res = bcnn(res, i);
        cout << res << endl;
    }
}

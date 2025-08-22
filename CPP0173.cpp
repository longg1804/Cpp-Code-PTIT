#include <bits/stdc++.h>
using namespace std;
#define int long long 
int bcnn (int a, int b) {
    return a / __gcd(a, b) * b;
}
int t, x, y, z, n, s, mod;
int l[20], r[20];
signed main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    l[1] = 1; r[1] = 10;
    for (int i = 2; i <= 18; ++i) {
        l[i] = l[i - 1] * 10;
        r[i] = r[i - 1] * 10;
    }
    for (int i = 1; i <= 18; ++i) --r[i];
    // for (int i = 1; i <= 18; ++i) cout << l[i] << " " << r[i] << endl;
    cin >> t;
    while (t--) {
        cin >> x >> y >> z >> n;
        s = bcnn(x, bcnn(y, z));
        if (s > r[n]) cout << -1 << endl;
        else
        if (l[n] % s == 0) cout << l[n] << endl;
        else {
            int d = l[n] / s;
            cout << s * (d + 1) << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long powmod (long long x, long long n) {
    long long res = 1;
    x %= MOD;
    while (n) {
        if (n % 2 == 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}
int t, n, x;
int a[2005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        long long res = 0;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i)
            res += (a[i] * powmod(x, n - i - 1)) % MOD;
        cout << res << endl;
    }
}
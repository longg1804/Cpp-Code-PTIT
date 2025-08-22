#include <bits/stdc++.h>
using namespace std;
int n, t, k, d, s;
int a[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s = 0;
        d = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            int d = upper_bound(a + i + 1, a + n, k - a[i]) - a;
            cout << i << " " << d << endl;
        }
        cout << s << endl;
    }
}
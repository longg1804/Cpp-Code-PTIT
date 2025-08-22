#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int a[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        int kt = 0;
        for (int i = 1; i <= n; ++i)
            if (binary_search(a + 1, a + n + 1, a[i] + x)) {
                kt = 1;
                break;
            }
        if (kt) cout << 1 << endl;
        else cout << -1 << endl;
    }
}
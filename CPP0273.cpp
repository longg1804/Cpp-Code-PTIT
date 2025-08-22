#include <bits/stdc++.h>
using namespace std;
int t, n;
int l[100005], r[100005], a[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        l[0] = 0; r[n + 1] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            l[i] = l[i - 1] + a[i];
        }
        for (int i = n; i >= 1; --i) r[i] = r[i + 1] + a[i];
        int kt = 0;
        for (int i = 1; i < n; ++i) 
            if (l[i - 1] == r[i + 1]) {
                cout << i << endl;
                kt = 1;
                break;
            }
        if (!kt) cout << -1 << endl;
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
int a[100005];
signed main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            int s;
            if (i == 1) s = a[1] * a[2];
            else 
            if (i == n) s = a[n - 1] * a[n];
            else s = a[i - 1] * a[i + 1];
            cout << s << " ";
        }
        cout << endl;
    } 
}
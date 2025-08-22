#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int maxx = 0;
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                maxx = max(maxx, a[j] - a[i]);
        cout << (maxx == 0 ? -1 : maxx) << endl;
    }
}
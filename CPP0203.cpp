#include <bits/stdc++.h>
using namespace std;
int t, n, MAX;
int a[100005], b[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            MAX = max(a[i], MAX);
        }
        for (int i = 1; i <= MAX; ++i) b[i] = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i] > 0) ++b[a[i]];
        int res = MAX + 1;
        for (int i = 1; i <= MAX; ++i)
            if (b[i] == 0) {
                res = i;
                break;
            }
        cout << res << endl;
    }
}
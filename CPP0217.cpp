#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[10005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n * n; ++i) cin >> a[i];
        a[n * n + 1] = -1;
        sort(a + 1, a + n * n + 1);
        int d = 1, MIN = a[1];
        int j = 1;
        // while (t != k) {
        //     while (a[j] == a[j + 1]) ++j;
        //     MIN = a[j + 1];
        //     ++j;
        //     ++d;
        // }
        // cout << MIN << endl;
        cout << a[k] << endl;
        // for (int i = 1; i <= n * n; ++i) cout << a[i] << " ";
    }
}
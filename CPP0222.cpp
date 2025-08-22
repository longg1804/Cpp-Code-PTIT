#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[105][105];
int b[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    int MAX = 0;
    while (t--) {
        cin >> n;
        int d = 0;
        for (int i = 1; i <= MAX; ++i) b[i] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) cin >> a[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (b[a[i][j]] == i - 1) ++b[a[i][j]];
                MAX = max(MAX, a[i][j]);
            }
        for (int i = 0; i <= MAX; ++i)
            if (b[i] == n) ++d;
        cout << d << endl;
    }
}
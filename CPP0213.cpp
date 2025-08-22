#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int a[105];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int f[100];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 100; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] >= 1000) {
            x = i;
            break;
        }
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (binary_search(f, f + x + 1, a[i])) cout << a[i] << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int t, n, p;

int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> p;
        if (p > n) cout << 0 << endl;
        else {
            int d = 0;
            for (int i = p; i <= n; ++i)
                if (i % p == 0) {
                    int x = i;
                    while (x % p == 0) {
                        ++d;
                        x /= p;
                    }
                }
            cout << d << endl;
        }
    }
}
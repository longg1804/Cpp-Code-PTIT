#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    int f[10005];
    for (int i = 1; i <= 10000; ++i) f[i] = 99999;
    for (int i = 2; i <= sqrt(10000); ++i)
        if (f[i] == 99999) {
            f[i] = i;
            for (int j = i * i; j <= 10000; j += i) f[j] = min(f[j], i);
        }
    for (int i = 1; i <= 10000; ++i)
        if (f[i] == 99999) f[i] = i;
    //for (int i = 1; i <= 10000; ++i) cout << f[i] << " ";
    //cout << f[101] << endl;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cout << f[i] << " ";
        cout << endl;
    }
}
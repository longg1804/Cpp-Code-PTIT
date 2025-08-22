#include <bits/stdc++.h>
using namespace std;
int t, l, r;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int f[10005];
    for (int i = 2; i <= 10000; ++i) f[i] = 1;
    for (int i = 1; i <= sqrt(10000); ++i)
        if (f[i] == 1) 
            for (int j = i * i; j <= 10000; j += i) f[j] = 0;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int d = 0;
        for (int i = l; i <= r; ++i)
            if (f[i] == 1) ++d;
        cout << d << endl;
    }
}
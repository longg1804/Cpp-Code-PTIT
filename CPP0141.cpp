#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long f[93];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < 93; ++i)
        f[i] = f[i - 1] + f[i - 2];
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (binary_search(f, f + 93, n) ? "YES" : "NO") << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
bool nt (int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}
long long t, n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        n = round(sqrt(n) - 0.5);
        int d = 0;
        for (int i = 2; i <= n; ++i)
            if (nt(i)) ++d;
        cout << d << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
bool nt (int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}
int t;
long long l, r;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> l >> r;
        l = sqrt(l);
        r = sqrt(r);
        int d = 0;
        for (int i = l; i <= r; ++i) 
            if (nt(i)) ++d;
        cout << d << endl;
    }
}
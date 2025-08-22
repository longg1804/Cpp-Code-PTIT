#include <bits/stdc++.h>
using namespace std;
long long kt(long long n) {
    if (n == 1) return 1;
    long long s = 1;
    for (int i = 2; i < sqrt(n); ++i)
        if (n % i == 0) s += i + (n / i);
    if (round(sqrt(n)) * round(sqrt(n)) == n) return s + round(sqrt(n));
    return s;
}
int t;
long long n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        if (kt(n) == n) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
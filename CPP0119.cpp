#include <bits/stdc++.h>
using namespace std;
int check (int n) {
    int d = 0;
    for (int i = 2; i < sqrt(n); ++i)
        if (n % i == 0) {
            if (i % 2 == 0) ++d;
            if ((n / i) % 2 == 0) ++d;
        }
    if (round(sqrt(n)) == sqrt(n))
        if (n % 2 == 0) ++d;
    if (n % 2 == 0) ++d;
    return d;
}
int t, n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << check(n) << endl;
    }
}
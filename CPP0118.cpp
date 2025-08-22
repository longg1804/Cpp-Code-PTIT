#include <bits/stdc++.h>
using namespace std;
bool kt (int n) {
    if (n < 30) return false;
    int d = 0, x = 0;
    for (int i = 2; i <= sqrt(n); ++i) 
        while (n % i == 0) {
            if (x == i) return false;
            ++d;
            x = i;
            n /= i;
        }
    if (n != 0) ++d;
    if (d == 3) return true;
    return false;
}
int t, n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (kt(n) ? 1 : 0) << endl;
    }
}
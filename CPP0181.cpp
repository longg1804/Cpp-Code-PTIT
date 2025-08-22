// Tìm ước số chung lớn nhất của hai số P và Q, trong đó P lặp lại x lần số a và Q lặp lại y lần số a.
// Ví dụ a =2, x = 3, y =2 thì P=222, Q=22.

// gcd(P, Q) = số nhận được khi ghép a lặp lại đúng g = gcd(x, y) lần.
#include <bits/stdc++.h>
using namespace std;
int t;
long long a, x, y;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> x >> y;
        for (int i = 1; i <= __gcd(x, y); ++i) cout << a;
        cout << endl;
    }
}
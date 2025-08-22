#include <bits/stdc++.h>
using namespace std;
bool nt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}
int tong(int n) {
    if (nt(n)) return n;
    int s = 0;
    int d = 0;
    for (int i = 2; i <= sqrt(n); ++i) 
        if (n % i == 0) {
            d = 0;
            while (n % i == 0) {
                ++d;
                n /= i;
            }
            s += i * d;
        }
    if (n != 1) s += n;
    return s;
}
int n;
int a[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; 
        s += tong(a[i]);
    }
    cout << s << endl;
}
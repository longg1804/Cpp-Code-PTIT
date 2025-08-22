#include <bits/stdc++.h>
using namespace std;
bool knt(int n) {
    if (n < 2) return true;
    if (n % 2 == 0) return true;
    for (int i = 2; i <= sqrt(n); ++i) 
        if (n % i == 0) return true;
    return false;
}
int tcs(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
bool nt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}
int t, n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int f[1005];
    for (int i = 2; i <= 1000; ++i) f[i] = 1;
    for (int i = 2; i <= sqrt(1000); ++i)
        if (f[i] == 1) 
            for (int j = i * i; j <= 1000; j += i) f[j] = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        if (knt(n)) {
            int tcsn = tcs(n);
            int tcsnt = 0;
            for (int i = 2; i < sqrt(n); ++i) 
                if (n % i == 0) {
                    if (nt(i)) {
                        int x = n;
                        while (x / i == 0) {
                            tcsnt += tcs(i);
                            x /= i;
                        }
                        cout << i << endl;
                    }
                    if (nt(n / i)) {
                        int x = n;
                        while (x / (n / i) == 0) {
                            tcsnt += tcs(n /i);
                            x /= (n / i);
                        }
                        cout << n / i << endl;
                    }
                }
            if (round(sqrt(n)) * round(sqrt(n)) == n)
                if (nt(round(sqrt(n)))) tcsnt += 2 * tcs(round(sqrt(n)));
            if (tcsn == tcsnt) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
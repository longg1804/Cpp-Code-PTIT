#include <bits/stdc++.h>
using namespace std;
string s;
int t;
int solve (int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int n = 0;
        for (int i = 0; i < s.size(); ++i) n += s[i] - 48;
        while (n >= 10) n = solve(n);
        cout << (n == 9) << endl;
    }
}
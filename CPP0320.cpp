#include <bits/stdc++.h>
using namespace std;
int kt(string s) {
    if (s[0] == '0') return -1;
    int a[15];
    for (int i = 0; i <= 9; ++i) a[i] = 0;
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] > '9') || (s[i] < '0')) return -1;
        ++a[s[i] - 48];
    }
    for (int i = 0; i <= 9; ++i)
        if (a[i] == 0) return 0;
    return 1;
}
int t;
string s;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        if (kt(s)) cout << "YES" << endl;
        else 
        if (kt(s) == -1) cout << "INVALID" << endl;
        else cout << "NO" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
bool kt(string s) {
    if ((s[6] > s[5]) && (s[7] > s[6]) && (s[9] > s[7]) && (s[10] > s[9])) return true;
    if ((s[5] == s[6]) && (s[6] == s[7]) && (s[10] == s[9])) return true;
    int d = 0;
    for (int i = 5; i <= 10; ++i) {
        if ((s[i] == '6') || (s[i] == '8')) ++d;
    }
    if (d == 5) return true;
    return false;
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
        cout << "NO" << endl;
    }
}
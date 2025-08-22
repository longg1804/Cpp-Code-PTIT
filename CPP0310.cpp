#include <bits/stdc++.h>
using namespace std;
long long MIN (string s) {
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '6') s[i] = '5';
    return stoll(s);
}
long long MAX (string s) {
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '5') s[i] = '6';
    return stoll(s);
}
string a, b;
int t;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) { 
        cin >> a >> b;
        long long x = MIN(a) + MIN(b);
        long long y = MAX(a) + MAX(b);
        cout << x << " " << y << endl;
    }
}
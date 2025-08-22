#include <bits/stdc++.h>
using namespace std;
string s[10005];
bool kt (string s) {
    int d = 0;
    for (int i = 0; i < s.size(); ++i) 
        if (s[i] == '5') ++d;
    if (d == s.size()) return true;
    return false;
}
string cong1 (string s) {
    string c = "";
    for (int i = 0; i <= s.size(); ++i) c += '4';
    return c;
}
void dao (string s) {
    for (int i = s.size() - 1; i >= 0; --i) cout << s[i]; 
}
string c;
int t, n;
int a[10005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k = 2;
    string c = "4";
    s[1] = c;
    cin >> t;
    int MAX = 0;
    for (int i = 1; i <= t; ++i) {
        cin >> a[i];
        MAX = max(a[i], MAX);
    }
    while (k <= MAX) {
        if (kt(c)) {
            c = cong1(c);
        }
        else {
            if (c[c.size() - 1] == '4') c[c.size() - 1] = '5';
            else {
                int d = c.size() - 1;
                while (c[d] == '5') --d;
                c[d] = '5';
                for (int i = d + 1; i < c.size(); ++i) c[i] = '4';
            }
        }
        s[k++] = c;
    }
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= a[i]; ++j) {
            cout << s[j];
            dao(s[j]);
            cout << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
string a, b;
int t;
string cong(string a, string b) {
    string c = "";
    int x, y, du = 0, s;
    char t;
    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;
    for (int i = a.size() - 1; i >= 0; --i) {
        x = a[i] - 48;
        y = b[i] - 48;
        s = x + y + du;
        if (s > 9) {
            t = (s % 10) + 48;
            du = 1;
        }
        else {
            t = s + 48;
            du = 0;
        }
        c = t + c;
    }
    if (du == 1) return '1' + c;
    else return c;
}
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << cong(a, b) << endl;
    }
}
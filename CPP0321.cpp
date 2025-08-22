#include <bits/stdc++.h>
using namespace std;
string tru(string d, string k) {
    string a = d, b = k;
    if (a == "0") return b;
    if (b == "0") return a;
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) swap(a, b);
    string c = "";
    char t;
    int x, y, du = 0, s;
    while (b.size() < a.size()) b = '0' + b;
    for (int i = a.size() - 1; i >= 0; --i) {
        x = a[i] - 48;
        y = b[i] - 48;
        s = x - y - du;
        if (s < 0) {
            s += 10;
            du = 1;
        }
        else du = 0;
        t = s + 48;
        c = t + c;
    }
    return c;
}
int t;
string a, b;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << tru(a, b) << endl;
    }
}
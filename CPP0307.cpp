#include <bits/stdc++.h>
using namespace std;
int t;
string a, b;
string x[205], y[205];
int s[205];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, a);
        int ia = 0;
        string c = "";
        for (int i = 0; i < a.size(); ++i)
            if (a[i] == ' ') {
                if (c != "") x[++ia] = c;
                c = "";
            } else c += a[i];
        if (c != "") x[++ia] = c;
        c = "";
        sort(x + 1, x + ia + 1);
        getline(cin, b);
        int ib = 0;
        for (int i = 0; i < b.size(); ++i)
            if (b[i] == ' ') {
                if (c != "") y[++ib] = c;
                c = "";
            } else c += b[i];
        if (c != "") y[++ib] = c;
        for (int i = 1; i <= ia; ++i) s[i] = 0;
        for (int i = 1; i <= ib; ++i)
            for (int j = 1; j <= ia; ++j)
                if (y[i] == x[j]) s[j] = 1;
        cout << endl;
    }
}
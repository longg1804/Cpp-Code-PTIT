#include <bits/stdc++.h>
using namespace std;
bool cmp (string a, string b) {
    while (a.size() < b.size()) a += a[0];
    while (b.size() < a.size()) b += b[0];
    for (int i = 0; i < a.size(); ++i)
        if (a[i] < b[i]) return 1;
    return 0;
}
int t, n;
string s[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> s[i];
        string c;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j <= n; ++j)
                if (cmp(s[i], s[j])) {
                    c = s[i];
                    s[i] = s[j];
                    s[j] = c;
                }
        for (int i = 1; i <= n; ++i) cout << s[i];
        cout << endl;
    }
}
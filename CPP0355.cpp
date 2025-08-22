#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CPP0355.inp", "r", stdin);
    freopen("CPP0355.out", "w", stdout);
    while (getline(cin, s)) {
    // getline(cin, s);
    for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
    while (s.find("  ") != string::npos) s.erase(s.find("  "), 1);
    int d = 0;
    if (s[d] == ' ') ++d;
    s[d] = toupper(s[d]);
    for (int i = d; i <= s.size(); ++i) {
        if (((s[i] == '.') || (s[i] == '?') || (s[i] == '!')) && (i < s.size() - 1)) s[i + 2] = toupper(s[i + 2]);
        else
        if ((s[i - 1] == '.') || (s[i - 1] == '?') || (s[i - 1] == '!')) cout << endl;
        else
        if ((s[i] == ' ') && ((s[i - 1] == ',') || (s[i] == ':'))) continue;
        else cout << s[i];
    }
    cout << endl;
    }
}
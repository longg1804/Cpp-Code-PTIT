#include <bits/stdc++.h>
using namespace std;
bool (kt) (string s){
    if (s[s.size() - 1] == '2') return false;
    int cs2, cs3, cs5, cs7;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '2') ++cs2;
        if (s[i] == '3') ++cs3;
        if (s[i] == '5') ++cs5;
        if (s[i] == '7') ++cs7;
    }
    if ((cs2 != 0) && (cs3 != 0) && (cs5 != 0) && (cs7 != 0)) return true;
    return false;
}
bool kt1 (string s) {
    int d = 0;
    for (int i = 0; i < s.size(); ++i) 
        if (s[i] == '7') ++d;
    if (d == s.size()) return true;
    return false;
}
void cong(char s) {
    if (s == '2') s == '3';
    if (s == '3') s == '5';
    if (s == '5') s == '7';
}
string cong1 (string s) {
    string c = "357";
    for (int i = 0; i <= s.size() - 2; ++i) c = '2' + c;
    return c;
}
int n;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    string a = "532";
    for (int i = 1; i <= n - 3; ++i) a = '7' + a;
    string s = "7777";
    while (s != a) {
        if (kt1(s)) s = cong1(s);
        if (kt(s)) cout << s << endl;
        if (s[s.size() - 1] != '7') cong(s[s.size() - 1]);
        else {
            int j = s.size() - 1;
            while (s[j] == '7') --j;
            cong(s[j]);
            for (int i = j + 1; i < s.size() - 1; ++i) s[i] = '2';
            s[s.size() - 1] = '3';
        }
    }
}
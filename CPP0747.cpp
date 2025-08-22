#include <bits/stdc++.h>
using namespace std;
int t, d;
string s;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int d = 0;
        while (s.find("100") != string::npos) {
            d += 3;
            s.erase(s.find("100"), 3);
        }
        cout << d << endl;
    }
}
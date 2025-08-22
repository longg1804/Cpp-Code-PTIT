#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100005], b[100005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] != 0) b[i] = 1;
            else b[i] = 0;
        }
        for (int i = 1; i < n; ++i) 
            if ((b[i + 1] != 0) && (a[i] == a[i + 1])) {
                a[i] *= 2;
                a[i + 1] = 0;
            }
        int d = n;
        for (int i = 1; i <= n; ++i)
            if (a[i] != 0) {
                cout << a[i] << " ";
                --d;
            }
        for (int i = 1; i <= d; ++i) cout << "0 ";
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200][200];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) cin >> a[i][j];
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) 
                for (int j = 1; j <= n; ++j) cout << a[i][j] << " ";
            else 
                for (int j = n; j >= 1; --j) cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
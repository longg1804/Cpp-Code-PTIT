#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005], chan[1005], le[1005];
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int c = 0, l = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) chan[++c] =  a[i];
        else le[++l] = a[i];
    }
    sort(chan + 1, chan + c + 1);
    sort(le + 1, le + l + 1, greater<int>());
    c = 1; l = 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] % 2 == 1) cout << le[l++] << " ";
        else cout << chan[c++] << " ";
}
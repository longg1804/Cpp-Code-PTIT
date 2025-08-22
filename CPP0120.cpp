#include <bits/stdc++.h>
using namespace std;
int t, l, r, a, b;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> l >> r >> a >> b;
        int d = 0;  
        for (int i = l; i <= r; ++i) 
            if ((i % a == 0) || (i % b == 0)){
                //cout << i << endl;
                ++d;
            }
        cout << d << endl;
    }
}
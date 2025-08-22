#include <bits/stdc++.h>
using namespace std;
bool nt (int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) 
        if (n % i == 0) return false;
    return true;
}
int a, b;
int main() {
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for (int i = min(a, b); i <= max(a, b); ++i)
        if (nt(i)) cout << i << " ";
}
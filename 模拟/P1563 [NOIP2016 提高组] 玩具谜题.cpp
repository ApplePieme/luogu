#include <bits/stdc++.h>
using namespace std;

int n, m, pos = 0, d;
int zyfx[100001], czfx[100001], czsl[100001];
string zy[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> zyfx[i] >> zy[i];
    for (int i = 0; i < m; ++i) cin >> czfx[i] >> czsl[i];
    for (int i = 0; i < m; ++i) {
        if (czfx[i] ^ zyfx[pos] == 1) {
            d = pos + czsl[i];
            if (d >= n) 
                pos = d - n;
            else
                pos = d;
        } else {
            d = pos - czsl[i];
            if (d < 0) 
                pos = d + n;
            else
                pos = d;
        }
    }
    cout << zy[pos];
    return 0;
}
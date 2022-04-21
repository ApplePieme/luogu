#include <bits/stdc++.h>
using namespace std;

string a, b;
int ans[4010], arr[2005], brr[2005];
int an = 0, bn = 0, limit;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    an = a.size();
    bn = b.size();
    limit = an + bn;
    for (int i = 0; i < an; ++i) {
        arr[i] = a[an - i - 1] - '0';
    }
    for (int i = 0; i < bn; ++i) {
        brr[i] = b[bn - i - 1] - '0';
    }
    for (int i = 0; i < an; ++i) {
        for (int j = 0; j < bn; ++j) {
            ans[i + j] += arr[i] * brr[j];
        }
    }
    for (int i = 0; i < limit; ++i) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while (ans[limit] == 0 && limit > 0) {
        --limit;
    }
    for (int i = limit; i >= 0; --i) {
        cout << ans[i];
    }
    return 0;
}
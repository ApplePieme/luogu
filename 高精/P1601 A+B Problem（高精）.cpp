#include<bits/stdc++.h>
using namespace std;

int a[501], b[501], c[502];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    string str_a, str_b;
    cin >> str_a >> str_b;
    if (str_a == "0" && str_b == "0") {
        cout << 0;
        exit(0);
    }
    int len_a = (int)str_a.size();
    for (int i = 0; i < len_a; ++i) a[i] = str_a[len_a - i - 1] - '0';
    int len_b = (int)str_b.size();
    for (int i = 0; i < len_b; ++i) b[i] = str_b[len_b - i - 1] - '0';
    int jw = 0;
    int len_min = min(len_a, len_b);
    for (int i = 0; i < len_min; ++i) {
        c[i] = a[i] + b[i] + jw;
        jw = c[i] / 10;
        c[i] %= 10;
    }
    if (len_min == len_a) {
        for (int i = len_min; i < len_b; ++i) {
            c[i] = b[i] + jw;
            jw = c[i] / 10;
            c[i] %= 10;
        }
        if (jw > 0) c[len_b] = jw;
    } else {
        for (int i = len_min; i < len_a; ++i) {
            c[i] = a[i] + jw;
            jw = c[i] / 10;
            c[i] %= 10;
        }
        if (jw > 0) c[len_a] = jw;
    }
    bool f = false;
    for (int i = 501; i >= 0; --i) {
        if (c[i] != 0) f = true;
        if (f) cout << c[i];
    }
    return 0;
}
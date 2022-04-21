#include <bits/stdc++.h>
using namespace std;

string s, t;
int n = 0, w = 0, l = 0;

void cot(int f) {
    w = 0;
    l = 0;
    for (const auto &c : s) {
        if (c == 'E') break;
        if (c == 'W') 
            ++w;
        else
            ++l;
        if ((w >= f || l >= f) && abs(w - l) >= 2) {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
    }
    cout << w << ":" << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> t) s += t;
    cot(11);
    cout << endl;
    cot(21);
    return 0;
}
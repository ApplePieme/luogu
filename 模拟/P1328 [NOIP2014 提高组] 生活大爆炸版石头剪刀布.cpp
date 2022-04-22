#include <bits/stdc++.h>
using namespace std;

int n, na, nb, ac, bc;
int a[201], b[201];
unordered_set<int> w[] = {{2, 3}, {0, 3}, {1, 4}, {2, 4}, {0, 1}};

int main() {
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++) cin >> a[i];
    for (int i = 0; i < nb; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        int ai = i % na, bi = i % nb;
        if (a[ai] != b[bi]) {
            if (w[a[ai]].count(b[bi])) {
                ac++;
            } else {
                bc++;
            }
        }
    }
    cout << ac << " " << bc << endl;
    return 0;
}
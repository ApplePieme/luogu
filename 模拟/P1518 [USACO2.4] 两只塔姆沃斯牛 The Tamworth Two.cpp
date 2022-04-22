#include <bits/stdc++.h>
using namespace std;

const int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char mat[10][10];
bool f[160005];
pair<int, int> f_pos, c_pos;
int ans, f_dir, c_dir, tz;

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'F') {
                f_pos = {i, j};
            }
            if (mat[i][j] == 'C') {
                c_pos = {i, j};
            }
        }
    }
    while (f_pos.first != c_pos.first || f_pos.second != c_pos.second) {
        tz = f_pos.first + f_pos.second * 10 + c_pos.first * 100 + c_pos.second * 1000 + (f_dir % 4) * 10000 + (c_dir % 4) * 40000;
        if (f[tz]) {
            cout << 0 << endl;
            return 0;
        }
        f[tz] = true;
        int f_newi = f_pos.first + dir[f_dir % 4][0], f_newj = f_pos.second + dir[f_dir % 4][1];
        int c_newi = c_pos.first + dir[c_dir % 4][0], c_newj = c_pos.second + dir[c_dir % 4][1];
        if (f_newi >= 0 && f_newi < 10 && f_newj >= 0 && f_newj < 10 && mat[f_newi][f_newj] != '*') {
            f_pos = {f_newi, f_newj};
        } else {
            f_dir++;
        }
        if (c_newi >= 0 && c_newi < 10 && c_newj >= 0 && c_newj < 10 && mat[c_newi][c_newj] != '*') {
            c_pos = {c_newi, c_newj};
        } else {
            c_dir++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
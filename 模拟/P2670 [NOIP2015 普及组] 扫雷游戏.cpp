#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[101][101];
const int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == '*') {
                for (int k = 0; k < 8; ++k) {
                    if (i + dir[k][0] >= 0 && i + dir[k][0] < n && j + dir[k][1] >= 0 && j + dir[k][1] < m) {
                        if (mat[i + dir[k][0]][j + dir[k][1]] == '?') {
                            mat[i + dir[k][0]][j + dir[k][1]] = '1';
                        } else if (mat[i + dir[k][0]][j + dir[k][1]] == '*') {
                            continue;
                        } else {
                            mat[i + dir[k][0]][j + dir[k][1]]++;
                        }
                    }
                }
            } else if (mat[i][j] == '?') {
                mat[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << mat[i][j];
        cout << endl;
    }
    return 0;
}
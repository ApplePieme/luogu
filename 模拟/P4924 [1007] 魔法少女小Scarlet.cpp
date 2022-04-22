#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, r, z, tx, ty, num = 1;
int mat[501][501], tmp[501][501];

void foo() {
    if (z == 0) {
        ty = y + r;
        for (int i = x - r; i <= x + r; i++) {
            tx = x - r;
            for (int j = y - r; j <= y + r; j++) {
                tmp[tx++][ty] = mat[i][j];
            }
            ty--;
        }
    } else {
        ty = y - r;
        for (int i = x - r; i <= x + r; i++) {
            tx = x + r;
            for (int j = y - r; j <= y + r; j++) {
                tmp[tx--][ty] = mat[i][j];
            }
            ty++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = num;
            tmp[i][j] = num++;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> r >> z;
        x--;
        y--;
        foo();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
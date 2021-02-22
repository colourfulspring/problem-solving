#include <cstdio>

int main() {
    int t;
    int a[50][50];
    scanf("%d", &t);
    while (t--) {
        int m, n;
        int ucla_rows = 0, ucla_cols = 0;
        int temp = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            temp = 0;
            for (int j = 0; j < m; j++) {
                scanf("%d", a[i] + j);
                temp += a[i][j];
            }
            if (temp == 0)
                ucla_rows++;
        }
        for (int i = 0; i < m; i++) {
            temp = 0;
            for (int j = 0; j < n; j++) {
                temp += a[j][i];
            }
            if (temp == 0)
                ucla_cols++;
        }
        int min = ucla_cols < ucla_rows ? ucla_cols : ucla_rows;
        if (min % 2 == 0) {
            printf("Vivek\n");
        } else {
            printf("Ashish\n");
        }
    }
    return 0;
}

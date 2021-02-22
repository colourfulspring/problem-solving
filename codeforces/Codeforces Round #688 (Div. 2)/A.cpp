#include <cstdio>

int a[102];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, ans = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= 100; ++i) {
            a[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int q;
            scanf("%d", &q);
            a[q]++;
        }
        for (int i = 0; i < m; ++i) {
            int q;
            scanf("%d", &q);
            if (a[q] == 1)ans++;
        }
        printf("%d\n", ans);
    }
}

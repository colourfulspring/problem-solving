#include <cstdio>

int main() {
    int t;
    int a[500], b[500];
    scanf("%d", &t);
    while (t--) {
        int n, tot = 0;
        bool increased = true;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", b + i);
            tot += b[i];
        }
        if (tot > 0 && tot < n) {
            printf("YES\n");
        } else {
            for (int i = 0; i < n - 1; i++) {
                increased &= (a[i] <= a[i + 1]);
            }
            printf(increased ? "YES\n" : "NO\n");
        }
    }
    return 0;
}

#include <cstdio>

int a[52];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long evenSum = 0, sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            sum += a[i];
            if (i % 2 == 0) evenSum += a[i];
        }
        if (evenSum > sum / 2) {
            for (int i = 1; i < n; i += 2) {
                a[i] = 1;
            }
        } else {
            for (int i = 0; i < n; i += 2) {
                a[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        putchar('\n');
    }
}

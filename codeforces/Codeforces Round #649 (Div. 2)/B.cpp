#include <cstdio>

int p[100007];
int list[100007];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int k = 1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", p + i);
        }
        list[0] = p[0];
        for (int i = 1; i < n - 1; i++) {
            if ((p[i - 1] < p[i] && p[i + 1] < p[i]) ||
                (p[i - 1] > p[i] && p[i + 1] > p[i])) {
                list[k++] = p[i];
            }
        }
        list[k++] = p[n - 1];
        printf("%d\n", k);
        for (int i = 0; i < k; i++) {
            printf("%d ", list[i]);
        }
        putchar('\n');
    }
    return 0;
}

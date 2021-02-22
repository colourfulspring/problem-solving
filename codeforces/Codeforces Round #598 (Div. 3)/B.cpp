#include <cstdio>

int q, n;
int a[103];
bool swapped[103] = {false};

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            swapped[i] = false;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (a[i + 1] < a[i]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped[i] = true;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (a[i + 1] < a[i] && !swapped[i]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        putchar('\n');
    }
}
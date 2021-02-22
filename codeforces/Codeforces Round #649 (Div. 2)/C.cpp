#include <cstdio>

int a[100007];
int flag[100007] = {0};
int b[100007];

int main() {
    int n;
    int p = 0;
    bool possible = true;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        flag[t] |= 1;
        a[i] = t;
    }
    if (a[0] > 0) {
        b[0] = 0;
        flag[0] |= 1;
        p = 1;
    } else {
        for (; p < n; p++) {
            if (flag[p] == 0)
                break;
        }
        b[0] = p++;
        flag[1] |= 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            b[i] = a[i - 1];
        } else {
            for (; p < n; p++) {
                if (flag[p] == 0)
                    break;
            }
            b[i] = p++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}

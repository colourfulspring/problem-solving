#include <cstdio>

#define SUB_MOD_X(a, b, x) a >= b ? a - b : a - b + x
#define ADD_MOD_X(a, b, x) a + b >= x ? a + b - x : a + b

int left[100007] = {0};
int right[100007] = {0};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        int p1 = 0, p2 = 0;
        int len;
        bool find = false;
        scanf("%d %d", &n, &x);
        left[0] = 0;
        for (int i = 0; i < n; i++) {
            int m = 0;
            scanf("%d", &m);
            left[i + 1] = ADD_MOD_X(m % x, left[i], x);
        }
        right[0] = 0;
        for (int i = 1; i <= n; i++) {
            right[i] = SUB_MOD_X(left[n], left[n - i], x);
        }
        for (int i = n; i > 0; i--) {
            if (left[i] != 0 || right[i] != 0) {
                find = true;
                len = i;
                break;
            }
        }
        printf(find ? "%d\n" : "-1\n", len);
    }
    return 0;
}

#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int a[1003];
        int even_at_odd_pos = 0, odd_at_even_pos = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            if (i % 2 == 0) {
                if (a[i] % 2 != 0)
                    odd_at_even_pos++;
            } else {
                if (a[i] % 2 == 0)
                    even_at_odd_pos++;
            }
        }
        if (odd_at_even_pos == even_at_odd_pos) {
            printf("%d\n", odd_at_even_pos);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}

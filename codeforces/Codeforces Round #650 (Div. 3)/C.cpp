#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int tot = 0;
        int count = k;
        for (int i = 0; i < n; i++) {
            char c;
            while ((c = getchar()) == '\n')
                ;
            if (c == '1') {
                tot += (count - k) / (k + 1);
                count = 0;
            } else {
                count++;
            }
        }
        tot += count / (k + 1);
        printf("%d\n", tot);
    }
    return 0;
}

#include <cstdio>

int main() {
    int t;
    char a[103], b[103];
    scanf("%d", &t);
    while (t--) {
        char *p, *q;
        scanf("%s", b);
        a[0] = b[0];
        for (p = a + 1, q = b + 1; *(q + 1) != '\0'; q += 2, p += 1) {
            *p = *q;
        }
        *p = *q;
        p++;
        *p = '\0';
        printf("%s\n", a);
    }
    return 0;
}

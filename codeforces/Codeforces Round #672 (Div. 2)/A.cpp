#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a[50008];
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        bool c = false;
        int i;
        for (i = 1; i < n; ++i) {
            if (a[i] >= a[i - 1]) {
                c = true;
                break;
            }
        }
        printf(c ? "YES\n" : "NO\n");
    }
}

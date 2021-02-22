#include <cstdio>
#include <algorithm>

#define LEFT(i) i>0?a[i-1]:(int)0xffffffff
#define RIGHT(i) i<n-1?a[i+1]:(int)0xffffffff
#define SUBNUM(left, right) for(int i=left;i<=right;++i){\
        if(result[i] == 1){                             \
            sum -= a[i];\
        }else if(result[i] == -1){\
            sum += a[i];\
        }\
}
#define ADDNUM(left, right) for(int i=left;i<=right;++i){\
        if(a[i] > (LEFT(i)) && a[i] > (RIGHT(i))){       \
            sum += a[i];                                 \
            result[i] = 1;                                \
        }else if(a[i] < (LEFT(i)) && a[i] < (RIGHT(i))){  \
            sum -= a[i];                                 \
            result[i] = -1;                              \
        }else {                                          \
            result[i] = 0;\
        }\
}
using namespace std;

int a[300008];
int result[300008];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        long long sum = 0;
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        ADDNUM(0, n - 1)
        printf("%lld\n", sum);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            --l;
            --r;
            if (abs(l - r) > 3) {
                SUBNUM(max(0, l - 1), l + 1);
                SUBNUM(r - 1, min(n - 1, r + 1));
            } else {
                SUBNUM(max(0, l - 1), min(n - 1, r + 1))
            }
            swap(a[l], a[r]);
            if (abs(l - r) > 3) {
                ADDNUM(max(0, l - 1), l + 1);
                ADDNUM(r - 1, min(n - 1, r + 1));
            } else {
                ADDNUM(max(0, l - 1), min(n - 1, r + 1))
            }
            printf("%lld\n", sum);
        }
    }
}


#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int sum = a + b + c;
        int minimum = min(min(a, b), c);
        if (sum % 9 == 0 && minimum >= sum / 9) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}

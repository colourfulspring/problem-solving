#include <cstdio>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    long long differ = 0;
    long long a = 1;
    scanf("%lld", &n);
    while (a <= n) {
      differ += n / a;
      a <<= 1;
    }
    printf("%lld\n", differ);
  }
  return 0;
}

#include <algorithm>
#include <cstdio>

using namespace std;
int main() {
  int t;
  int s[1024] = {0};
  bool flag[1024] = {0};
  int numlist[1024] = {0};
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 1024; i++) {
      flag[i] = false;
      numlist[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", s + i);
      flag[s[i]] = true;
    }
    if (n % 2 == 1) {
      printf("-1\n");
    } else {
      for (int i = 1; i < n; i++) {
        numlist[i - 1] = s[0] ^ s[i];
      }
      sort(numlist, numlist + n - 1);
      int i = 0;
      for (; i < n - 1; i++) {
        bool exist_num = true;
        if (!numlist[i])
          continue;
        for (int j = 0; j < n; j++) {
          exist_num &= flag[s[j] ^ numlist[i]];
        }
        if (exist_num)
          break;
      }
      printf(i < n - 1 ? "%d\n" : "-1\n", numlist[i]);
    }
  }
  return 0;
}

#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        vector<int> is_married;
        int min_single = 0;
        int unmarried_princess = -1;
        scanf("%d", &n);
        is_married.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            bool find_spouse = false;
            scanf("%d", &k);
            while (k--) {
                int p;
                scanf("%d", &p);
                --p;
                if (!find_spouse && !is_married[p]) {
                    find_spouse = true;
                    is_married[p] = 1;
                    if (p == min_single) {
                        while (min_single < is_married.size() && is_married[min_single]) ++min_single;
                    }
                }
            }
            if (!find_spouse && unmarried_princess == -1) {
                unmarried_princess = i;
            }
        }
        if (unmarried_princess != -1) {
            printf("IMPROVE\n%d %d\n", unmarried_princess + 1, min_single + 1);
        } else {
            printf("OPTIMAL\n");
        }
    }
}


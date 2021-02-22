#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, temp = 0;
		vector<int> a;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			a.push_back(temp);
		}
		sort(a.begin(), a.end());
		for (int i = n - 1; i >= 0; i--) {
			printf("%d ", a[i]);
		}
		putchar('\n');
	}
	return 0;
}
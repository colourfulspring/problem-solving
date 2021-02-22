#include <cstdio>
#include <set>

using namespace std;
int main() {
	int t;
	int n;
	int temp;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		set<int> a;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			a.insert(temp);
		}
		printf("%d\n", a.size());
	}
}


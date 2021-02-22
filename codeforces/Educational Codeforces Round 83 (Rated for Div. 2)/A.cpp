#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, n;
		scanf("%d%d", &n, &m);
		if (n % m == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
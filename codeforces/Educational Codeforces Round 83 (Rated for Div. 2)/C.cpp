#include <cstdio>
#include <vector>

using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k;
		long long temp;
		vector<int> a;
		a.resize(60);
		for (int i = 0; i < 60; i++) {
			a[i] = 0;
		}
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &temp);
			int j = 0;
			while (temp != 0)
			{
				a[j++] += temp % k;
				temp /= k;
			}
		}
		bool flag = true;
		for (int i = 0; i < 60; i++) {
			if (a[i] > 1) {
				flag = false;
				break;
			}
		}
		printf("%s", flag ? "YES\n" : "NO\n");
	}
	return 0;
}
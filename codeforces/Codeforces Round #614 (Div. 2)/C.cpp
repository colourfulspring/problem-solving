#include <cstdio>
#include <vector>

bool flag[16] = { true,true,true,true,true,false,false,false,true,false,false,false,true,false,false,false };

int change(int i, int j) {
	if (flag[i] && !flag[j]) {
		return 1;
	}
	else if (!flag[i] && flag[j]) {
		return -1;
	}else {
		return 0;
	}
}

using namespace std;
int main() {
	int n, q, tot = 0;
	scanf("%d %d", &n, &q);
	vector<int> map;
	map.resize(n + 5);
	for (int i = 0; i < q; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		int pos = (r == 1) ? 8 : 2;
		if (c > 1) {
			int next = map[c - 1] ^ pos;
			tot += change(map[c - 1], next);
			map[c - 1] = next;
		}
		if (c < n) {
			int next = map[c] ^ (pos >> 1);
			tot += change(map[c], next);
			map[c] = next;
		}
		printf("%s\n", tot == 0 ? "YES" : "NO");
	}
	return 0;
}
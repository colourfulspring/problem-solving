#include <iostream>

using namespace std;
int main()
{
	int t;

	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int gcd;
		for (gcd = 1; (x - gcd) % gcd != 0; gcd++);
		cout << gcd << ' '<< x - gcd << endl;
	}
	return 0;
}


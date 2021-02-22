#include <cstdio>

int main(){
	int t,n,x,a,b;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &n, &x, &a, &b);
		int max = a>b?a:b;
		int min = a + b - max;
		int res = max - min + x;
		if(res > n - 1) res = n - 1;
		printf("%d\n", res);
	}
	return 0;
} 

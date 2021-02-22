#include <cstdio>
#define mod 1000000007

int main(){
	long long n,m;
	scanf("%lld %lld", &n, &m);
	long long res = 1, p = 2;
	while(m != 0){
		if(m % 2 != 0)res = res * p % mod;
		p = p * p % mod;
		m >>= 1;
	}
	res--;
	p = res;
	res = 1;
	while(n != 0){
		if(n % 2 != 0)res = res * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	printf("%lld", res);
	return 0;
} 

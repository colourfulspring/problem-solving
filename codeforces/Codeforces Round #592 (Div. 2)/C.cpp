#include <cstdio>
#include <algorithm>
 
using namespace std;
long long gcd(long long a, long long b){
	long long c;
	if(a < b) swap(a,b);
	while(a % b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}
 
int main(){
	long long n,p;
	long long d,w;
	long long x,y,z;
	
	scanf("%lld %lld %lld %lld", &n,&p,&w,&d);
	if(n * w < p){
		printf("-1");
	}else{
		long long gcd1 = gcd(w, d);
		if(p % gcd1 != 0){
			printf("-1");
		}else{
			for(x = p / w;x >= 0;x--){
				if((p - x * w) % d == 0){
					y = (p - x * w) / d;
					if(y >= 0 && x + y <= n){
						z = n - x - y;
						printf("%lld %lld %lld", x, y, z);
						break;
					}
				}
			}
		}
		if(x < 0) printf("-1"); 
	}
	return 0;
}

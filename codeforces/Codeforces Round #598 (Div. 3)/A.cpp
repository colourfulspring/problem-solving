#include <cstdio>

int main(){
	int q;
	long long a,b,n,s;
	
	scanf("%d", &q);
	while(q--){
		scanf("%lld %lld %lld %lld", &a, &b, &n, &s);
		if(a * n + b < s){
			printf("NO\n");
		}else{
			if(s % n <= b){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
} 

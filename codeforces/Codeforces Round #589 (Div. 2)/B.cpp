#include <cstdio> 
#define mod 1000000007

int main(){
	int r[1001], c[1001];
	int h,w;
	int sum = 0;
	int res = 1;
	
	scanf("%d %d", &h, &w);
	for(int i = 1;i <= h;i++) scanf("%d", r + i);
	for(int j = 1;j <= w;j++) scanf("%d", c + j);
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			if(j <= r[i]){
				if(i == c[j]+1){
					printf("0");
					return 0;
				}else sum++;
			}else if(j == r[i]+1){
				if(i <= c[j]){
					printf("0");
					return 0;
				}else sum++;
			}else{
				if(i <= c[j] + 1) sum++; 
			}
		}
	}
	sum = h * w - sum;
	for(int i = 1;i <= sum;i++){
		 res = res * 2 % mod;
	}
	printf("%d", res);
}

#include <cstdio>

int main(){
	int l,r;
	scanf("%d %d", &l, &r);
	while(l <= r){
		bool flag[10] = {false};
		int p = l;
		while(p > 0){
			if(*(flag + p % 10)){
				break;
			}else{
				*(flag + p % 10) = true;
			}
			p /= 10;
		}
		if(p == 0) {
			printf("%d", l);
			break;
		}
		l++;
	}
	if(l > r) printf("-1");
	return 0;
} 

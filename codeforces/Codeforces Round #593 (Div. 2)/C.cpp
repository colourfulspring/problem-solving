#include <cstdio>

int main(){
	int n, m = 1;
	int a[302][302];
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		if(i % 2 == 0){
			for(int j = 0;j < n;j++){
				a[j][i] = m++;
			}
		}else{
			for(int j = n - 1;j >= 0;j--){
				a[j][i] = m++;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
	return 0;
} 

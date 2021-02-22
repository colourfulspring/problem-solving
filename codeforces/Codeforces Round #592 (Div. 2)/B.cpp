#include <cstdio>

int main(){
	int t;
	
	scanf("%d", &t);
	while(t--){
		int n;
		char key[1005];
		scanf("%d", &n);
		scanf("%s", key + 1);
		int i ,j;
		for(i = 1, j = n;i <= j;i++,j--){
			if(key[i] == '1' || key[j] == '1'){
				printf("%d\n", 2 *(n - i + 1));
				break;
			}
		}
		if(i > j){
			printf("%d\n", n);
		}
	}
	return 0;
}

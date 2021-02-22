#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		if(b >= 2 * a + c / 2){
			printf("%d\n", (a + c/2) * 3);
		}else{
			if(c >= 2*b){
				printf("%d\n", 3 * b);
			}else{
				printf("%d\n", c / 2 * 3 + min((b - c/2)/2, a)*3);
			}
		}
	}
	return 0;
} 

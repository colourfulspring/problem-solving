#include<cstdio>
using namespace std;
int main(){
	int t;
	int a[1001];
	scanf("%d", &t);
	while(t--){
		int n,s,k,temp;
		scanf("%d %d %d", &n, &s, &k);
		for(int i = 0;i < 1000;i++) a[i] = 0;
		for(int i = 0;i < k;i++){
			scanf("%d", &temp);
			int c = temp > s?temp-s:s-temp;
			if(c <= 1000) a[c]++;
		}
		temp = s-1>n-s?n-s:s-1;
		for(int i = 0;i <= 1000;i++){
			if(i <= temp && i > 0){
				if(a[i]!=2){
					printf("%d\n", i);
					break;
				}
			}else{
				if(a[i]!=1){
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
} 

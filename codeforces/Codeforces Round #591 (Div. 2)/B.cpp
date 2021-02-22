#include <cstdio>

int main(){
	bool flag[26];
	char s[105], t[105];
	int q;
	
	for(int i = 0;i < 26;i++) flag[i] = false;
	scanf("%d", &q);
	while(q--){
		scanf("%s", s);
		scanf("%s", t);
		char *p;
		for(int i = 0;i < 26;i++) flag[i] = false;
		for(p = s;*p != '\0';p++) flag[*p - 'a'] = true;
		for(p = t;*p != '\0';p++){
			if(flag[*p - 'a']){
				printf("YES\n");
				break;
			}
		}
		if(*p == '\0'){
			printf("NO\n");
		}
	}
	return 0;
} 

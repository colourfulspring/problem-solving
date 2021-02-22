#include <cstdio>

int n;
int c[3][100002] = {0};
int neigh[100002][2] = {0};
int sum[100002] = {0};
int path[100002] = {0};
bool isused[100002];
long long cost = 0, min = 1e16;
int minpos = 3;
int code[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
char color[100002];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < n;j++){
			scanf("%d", c[i] + j);
		}
	}
	for(int i = 0;i < n - 1;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		if(sum[x] == 2 || sum[y] == 2){
			printf("-1");
			return 0;
		}
		neigh[x][sum[x]++] = y;
		neigh[y][sum[y]++] = x;
	}
	int i, j;
	for(i = 0;sum[i] != 1;i++);
	path[0] = i;
	isused[i] = true;
	i = neigh[i][0];
	for(j = 1;sum[i] != 1;j++){
		path[j] = i;
		isused[i] = true;
		i = isused[neigh[i][0]] ? neigh[i][1] : neigh[i][0];
	}
	path[j] = i;
	for(i = 0;i < 6;i++){
		cost = 0;
		for(j = 0;j < n;j++){
			cost += c[code[i][j % 3]][path[j]];
		}
		if(cost < min){
			min = cost;
			minpos = i;
		}
	}
	printf("%lld\n", min);
	for(int i = 0;i < n;i++){
		color[path[i]] = '0' + code[minpos][i % 3];
	}
	for(int i = 0;i < n;i++){
		printf("%c ", color[i] + 1);
	}
	return 0;
} 

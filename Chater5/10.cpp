//음료수 얼려 먹기

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1000][1000];

bool dfs(int x, int y) {
	//주어진 범위를 벗어나면 즉시 종료
	if (x <= -1 || x >= n || y <= -1 || y >= m) return false;

	//현재 노드를 방문하지 않았다면
	if (arr[x][y] == 0) {
		arr[x][y] = 1;

		//상,하,좌,우의 위치들도 모두 재귀적으로 호출
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	//얼음틀 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]); //한문자씩 입력
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) result++;
		}
	}
	printf("%d\n", result);
}

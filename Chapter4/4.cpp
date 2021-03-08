//게임 개발

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int input_map[50][50]; //맵정보
int v[50][50] = {}; //방문한 위치 정보

void turnLeft() {
	d -= 1;
	if (d == -1) d = 3;
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &x, &y, &d);
	v[x][y] = 1; //현재 위치 방문

	//맵 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &input_map[i][j]);
		}
	}

	int cnt = 1;
	int turn_time = 0;

	while (1) {
		turnLeft();
		int nx = x + dx[d];
		int ny = y + dy[d];

		//정면에 가보지 않은 곳이 존재한다면
		if (v[nx][ny] == 0 && input_map[nx][ny] == 0) {
			v[nx][ny] = 1; //이동
			x = nx;
			y = ny;
			cnt++;
			turn_time = 0;
			continue;
		}
		else turn_time++;

		//네 방향 모두 갈 수 없는 경우
		if (turn_time == 4) {
			nx = x - dx[d];
			ny = y - dy[d];
			if (input_map[nx][y] == 0) { //뒤쪽 방향이 육지라면
				x = nx;
				y = ny;
			}
			else break; //바다일때
			turn_time = 0;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

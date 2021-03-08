//미로탈출

#include <bits/stdc++.h>
using namespace std;

int n, m;

int graph[201][201];

//이동할 방향 정의 - 상,하,좌,우
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y }); //삽입

	while (!q.empty()) { //큐가 빌때까지 반복
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//현재 위치에서 4가지 방향 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//맵을 벗어나면 다음으로 넘어감
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			//괴물이 있으면 다음으로 넘어감
			if (graph[nx][ny] == 0) continue;

			//해당 노드를 처음방문하면 최단거리 기록
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1; //이전 값+1(누적계산)
				q.push({ nx,ny });
			}
		}
	}
	return graph[n - 1][m - 1];
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	printf("%d\n", bfs(0, 0));
	return 0;
}

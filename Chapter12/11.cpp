//뱀
//https://www.acmicpc.net/problem/3190

#include <bits/stdc++.h>

using namespace std;

//동,남,서,북
int dx[] = { 0, 1, 0,-1 };
int dy[] = { 1,0,-1,0 };

int board[101][101];
int n, k; //보드의 크기, 사과개수
int nd; //방향횟수
vector<pair<int, char>> d; //방향(초,회전)

int changeD(int direction, char c) {
	if (c == 'L') direction = (direction == 0) ? 3 : direction - 1;
	else direction = (direction == 3) ? 0 : direction + 1;
	return direction;
}

int main()
{
	cin >> n >> k;

	//사과있는 위치 입력
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}

	//방향정보 입력
	cin >> nd;
	for (int i = 0; i < nd; i++) {
		int a;
		char c;
		cin >> a >> c;
		d.push_back({ a, c });
	}

	int x = 1,y = 1; //뱀의 머리위치
	board[x][y] = 2; //뱀이 존재

	int direction = 0;//방향
	int time = 0; //시간
	queue<pair<int, int>> q; //뱀이 차지하고 있는 위치 정보
	q.push({ x,y });

	while (1) {
		int nx = x + dx[direction]; //머리를 내밀 위치
		int ny = y + dy[direction]; //머리를 내밀 현재위치

		if (nx > n || nx <= 0 || ny > n || ny <= 0) {
			time++;
			break; //벽이면 종료
		}

		if (board[nx][ny] == 2) {
			time++;
			break; //자기자신과 닿으면 종료
		}
		else if (board[nx][ny] == 1) { //사과가 존재하면
			board[nx][ny] = 2; //꼬리 두기
			q.push({ nx,ny });
		}
		else if (board[nx][ny] == 0) { //사과가 존재하지 않으면
			board[nx][ny] = 2;
			q.push({ nx,ny });
			board[q.front().first][q.front().second] = 0; //꼬리 자르기
			q.pop();
		}

		//머리위치 갱신
		x = nx;
		y = ny;
		time++;

		//방향갱신
		for (int i = 0; i < nd; i++) {
			if (time == d[i].first) {
				direction = changeD(direction, d[i].second);
			}
		}
	}
	cout << time << '\n';

	return 0;
}

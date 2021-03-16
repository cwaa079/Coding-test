//연구소
//https://www.acmicpc.net/problem/14502

#include <bits/stdc++.h>
using namespace std;

int n, m; //지도의 세로,가로크기

int arr[8][8]; //초기 맵
int temp[8][8]; //벽 치고 난 후의 배열

int dx[] = { -1,0,1,0 }; //동남서북
int dy[] = { 0,1,0,-1 };

int result;

void virus(int x, int y) { //dfs를 이용해 바이러스를 사방으로 퍼지게
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) { //퍼지는 조건
			if (temp[nx][ny] == 0) {
				temp[nx][ny] = 2;
				virus(nx, ny); //재귀
			}
		}
	}
}

int getScore() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void dfs(int count) {

	if (count == 3) { //마지막 울타리라면
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		//virus 전파
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) virus(i, j);
			}
		}

		//안전영역의 최대값 계산
		result = max(result, getScore());
		return;
	}


	//울타리 설치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				count++;
				dfs(count);
				arr[i][j] = 0; //3개의 울타릴 모두 설치했으므로
				count--;
			}
		}
	}
}

int main()
{
	//정보입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);
	cout << result << '\n';
	return 0;
}

//인구이동
//https://www.acmicpc.net/problem/16234

#include <bits/stdc++.h>
using namespace std;

int n, l, r; // 크기, 인구차이(l이상 r이하)
int graph[50][50]; //인구수 저장
int unions[50][50]; //연합 정보

int dx[] = { -1, 0, 1, 0 }; //위왼아래오른
int dy[] = { 0, -1, 0, 1 };

bool check(int a, int b) { //인구이동가능여부
	int result = abs(a-b);
	if (l <= result && result <= r) return true;
	return false;
}

//특정한 위치에서 출발하여 모든 연합을 테크한 뒤에 데이터 갱신
void process(int x, int y, int index) { 
	vector <pair<int, int>> united; //(x,y)와 연결된 정보를 담는 리스트
	united.push_back({ x,y });

	//BFS
	queue<pair<int, int>> q;
	q.push({ x,y });
	unions[x][y] = index; //현재 연합의 번호
	int sum = graph[x][y]; //현재 연합의 전체 인구 수
	int cnt = 1; //현재 연합의 수

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; //확인할 도시
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n && unions[nx][ny]==-1) {
				if (check(graph[nx][ny], graph[x][y])) { //인구이동가능하다면
					q.push({ nx,ny });
					unions[nx][ny] = index; //연합번호 할당
					sum += graph[nx][ny];
					cnt++;
					united.push_back({ nx,ny });
				}
			}
		}
	}
	//연합 국가끼리 인구 분해
	for (int i = 0; i < united.size(); i++) {
		int x = united[i].first;
		int y = united[i].second;
		graph[x][y] = sum / cnt;
	}
}

int main()
{
	int total = 0;

	//정보저장
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	while (true) {
		//새로운 국가를 기준으로 연합 갱신
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				unions[i][j] = -1;
			}
		}
		int index = 0; //연합의 번호
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				if (unions[i][j] == -1) { //방문하지 않았던 국가라면
					process(i, j, index); //처리
					index++;
				}
			}
		}
		//모든 인구 이동이 끝난 경우
		if (index == n * n) break;
		total++;
	}
	cout << total;
	return 0;
}

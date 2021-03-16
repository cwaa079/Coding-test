//감시피하기
//https://www.acmicpc.net/problem/18428

#include <bits/stdc++.h>
using namespace std;

int n; //복도의 크기
char arr[6][6]; //복도의 정보

vector <pair<int, int>> teachers;//선생님위치 x,y
vector <pair<int, int>> spaces; //비어있는 위치 x,y

bool found; //원하는 경우 찾음/못찾음

bool watch(int x, int y, int direction) //학생발견 : true, 미발견 : false
{
	if (direction == 0) { //위쪽
		while (0 <= x) {
			if (arr[x][y] == 'S') return true; //학생이 있으면
			if (arr[x][y] == 'O') return false;
			x--;
		}
	}
	if (direction == 1) { //아래쪽
		while (x<n) {
			if (arr[x][y] == 'S') return true; //학생이 있으면
			if (arr[x][y] == 'O') return false;
			x++;
		}
	}
	if (direction == 2) { //왼
		while (0 <= y) {
			if (arr[x][y] == 'S') return true; //학생이 있으면
			if (arr[x][y] == 'O') return false;
			y--;
		}
	}
	if (direction == 3) { //오른
		while (y<n) {
			if (arr[x][y] == 'S') return true; //학생이 있으면
			if (arr[x][y] == 'O') return false;
			y++;
		}
	}
	return false;
}

bool check() {
	//벽 치기
	for (int i = 0; i < teachers.size(); i++) {
		int x = teachers[i].first;
		int y = teachers[i].second;

		for (int j = 0; j < 4; j++) {
			if (watch(x, y, j)) return true; //찾은 경우
		}
	}
	return false;
}

int main()
{
	cin >> n;
	//정보입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') teachers.push_back({ i,j });
			if (arr[i][j] == 'X') spaces.push_back({ i,j });
		}
	}

	//무작위로 3개를 뽑는 조함
	vector <bool> binary(spaces.size());
	fill(binary.end() - 3, binary.end(), true);

	do {
		//장애물 설치
		for (int i = 0; i < spaces.size(); i++) {
			if (binary[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				arr[x][y] = 'O';
			}
		}
		if (!check()) {
			found = true;
			break;
		}
		//장애물 삭제
		for (int i = 0; i < spaces.size(); i++) {
			if (binary[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				arr[x][y] = 'X';
			}
		}
	} while (next_permutation(binary.begin(), binary.end()));

	if (found) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}

//경쟁적 전염
//https://www.acmicpc.net/problem/18405

#include <bits/stdc++.h>
using namespace std;

//각 바이러스의 정보를 저장하는 클래스
class Virus { 
public:
	int x; //x좌표
	int y; //y좌표
	int vn; //바이러스 번호
	int vs; //시간

	Virus(int x, int y, int vn, int vs) {
		this->x = x;
		this->y = y;
		this->vn = vn;
		this->vs = vs;
	}

	bool operator <(Virus &other) {
		return this->vn < other.vn;
	}
};

int n, k; //맵크기, 바이러스번호
int s, sx, sy; //s초후 x,y좌표
int arr[200][200]; //보드의 정보

int dx[] = { -1, 0, 1, 0 }; //동남서북
int dy[] = { 0, 1, 0, -1 };

vector <Virus> viruses;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				viruses.push_back(Virus(i, j, arr[i][j], 0));
		}
	}
	cin >> s >> sx >> sy;

	//정렬이후 큐로 옮기기
	sort(viruses.begin(), viruses.end());
	queue<Virus> q;
	for (int i = 0; i < viruses.size(); i++) 
		q.push(viruses[i]);

	//BFS
	while (!q.empty()) {
		Virus virus = q.front(); //불러오고
		q.pop(); //삭제하고

		if (virus.vs == s) break; //지정한 초와 같으면 종료

		for (int i = 0; i < 4; i++) {
			int nx = virus.x + dx[i];
			int ny = virus.y + dy[i];

			//해당 위치로 이동가능하면
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				//방문하지 않은 노드라면 해당하는 바이러스 넣기
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = virus.vn;
					q.push(Virus(nx, ny, virus.vn, virus.vs));
				}
			}
		}
	}
	cout << arr[sx - 1][sy - 1] << '\n';
	return 0;
}

#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int graph[501][501];

int main()
{
	cin >> n >> m;

	//배열 무한대로 초기화
	for (int i = 0; i < 501; i++)
		fill(graph[i], graph[i] + 501, INF);

	//자기자신 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
		}
	}

	//간선에 대한 정보 입력받아서 저장
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	//플로이드 워셜 알고리즘
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	//출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF) cout << "INFINITY" << ' ';
			else cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

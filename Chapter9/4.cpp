//미래도시

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n; //전체 회사의 갯수
int m; //경로의 개수
int graph[101][101];

int main()
{
	cin >> n >> m;

	//무한으로 초기화
	for (int i = 0; i < 101; i++)
		fill(graph[i], graph[i] + 101, INF);

	//자기자신 = 0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
		}
	}

	//입력한 정보로 초기화(간선정보)
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int x; //최종목적지
	int k; //지나쳐야가하는 목적지
	cin >> x >> k;

	//플로이드 워셜 알고리즘
	for (int a = 1; a <= n; a++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][a] + graph[a][j]);
			}
		}
	}

	int dis = graph[1][k] + graph[k][x]; //x를 지나가는 k도착의 최단거리

	if (dis >= INF) cout << "-1\n";
	else cout << dis << '\n';

	return 0;
}

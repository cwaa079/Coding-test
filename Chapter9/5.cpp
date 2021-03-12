//전보

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, start; //도시개수, 통로개수, 시작
vector <pair<int, int>> graph[30001]; //노드,간선
int d[30001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq; //간선,노드
	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first; //간선 합
		int now = pq.top().second; //현재 노드
		pq.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;

	//간선 정보 입력
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	fill(d, d + 30001, INF); //d 초기화

	dijkstra(start);

	int cnt = 0; //도달한 노드
	int maxDistance = 0;

	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			cnt++;
			maxDistance = max(maxDistance, d[i]);
		}
	}
	cout << cnt - 1 << ' ' << maxDistance << '\n';
	return 0;
}

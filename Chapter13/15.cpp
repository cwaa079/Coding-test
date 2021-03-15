//특정 거리의 도시 찾기(최단거리)
//BFS이용

#include <bits/stdc++.h>

using namespace std;

int n, m, k, x; //도시개수, 도로개수, 거리정보, 출발도시번호
vector<int>graph[300001]; //노드와 간선 저장
vector<int>d(300001, - 1); //거리

int main()
{
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	//출발도시까지의 거리는 0
	d[x] = 0;

	//BFS 수행
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int nextNode = graph[now][i];

			if (d[nextNode] == -1) { //아직 방문하지 않은 도시라면
				d[nextNode] = d[now] + 1;
				q.push(nextNode);
			}
		}
	}

	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			check = true;
		}
	}

	if (!check) cout << -1 << '\n';

	return 0;
}

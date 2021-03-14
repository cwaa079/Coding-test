//치킨배달
//https://www.acmicpc.net/problem/15686

#include <bits/stdc++.h>

using namespace std;

int n, m; //도시의 크기, 폐업시키지 않을 치킨집
int city[51][51];
vector<pair<int, int>> house; //집이 있는 좌표
vector<pair<int, int>> chicken; //치킨집이 있는 좌표

int getSum(vector<pair<int, int>> now) { //치킨집
	int result = 0;

	for (int i = 0; i < house.size(); i++) {
		int hx = house[i].first;
		int hy = house[i].second;

		int mins = 1e9;
		for (int j = 0; j < now.size(); j++) {
			int nx = now[j].first;
			int ny = now[j].second;
			mins = min(mins, abs(hx - nx) + abs(hy - ny)); //거리계산
		}
		result += mins;
	}
	return result;
}

int main()
{
	//정보입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) house.push_back({ i,j });
			else if (city[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	//모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
	vector<bool> binary(chicken.size());
	fill(binary.end() - m, binary.end(), true);

	int minStreet = 1e9;

	do {
		vector<pair<int, int>> now;
		for (int i = 0; i < chicken.size(); i++) {
			if (binary[i]) {
				int nx = chicken[i].first;
				int ny = chicken[i].second;
				now.push_back({ nx, ny });
			}
		}
		minStreet = min(minStreet, getSum(now));
	} while (next_permutation(binary.begin(), binary.end())); //순열

	cout << minStreet << '\n';
	return 0;
}

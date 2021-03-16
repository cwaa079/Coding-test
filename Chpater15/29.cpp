//공유기 설치
//https://www.acmicpc.net/problem/2110

#include <bits/stdc++.h>
using namespace std;

int n, c; //집개수,공유기개수
vector <int> house;

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		house.push_back(a);
	}

	sort(house.begin(), house.end()); //정렬

	int start = 1; //가능한 최소 거리
	int end = house[n - 1] - house[0]; //가능한 최대거리
	int result = 0;

	//binarySearch
	while (start <= end) {
		int mid = (start + end) / 2; //가장 인접한 두 공유기 사이의 거리
		int value = house[0]; //첫째집에는 무조건 공유기를 설치한다고 가정
		int cnt = 1;

		for (int i = 1; i < n; i++) { //앞에서부터 차례대로 공유기 설치
			if (house[i] >= value + mid) {
				value = house[i];
				cnt++;
			}
		}
		if (cnt >= c) { //공유기를 더 설치할 수 있었다면
			start = mid + 1;
			result += mid;
		}
		else {
			end = mid - 1;
		}
	}

	return 0;
}

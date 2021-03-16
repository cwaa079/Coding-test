//연산자 끼워넣기
//https://www.acmicpc.net/problem/14888


#include <bits/stdc++.h>
using namespace std;

int n; //수의 개수
int arr[100]; //수열

vector <int> opN; //연산의 개수(+-*/)

int minValue = 1e9;
int maxValue = -1e9;

void dfs(int index, int now) {
	//now는 현재 누적된 값

	if (index == n) {
		minValue = min(minValue, now);
		maxValue = max(maxValue, now);
	}
	else {
		if (opN[0] > 0) {
			opN[0]--;
			dfs(index+1, now + arr[index]);
			opN[0]++;
		}
		if (opN[1] > 0) {
			opN[1]--;
			dfs(index + 1, now - arr[index]);
			opN[1]++;
		}
		if (opN[2] > 0) {
			opN[2]--;
			dfs(index + 1, now * arr[index]);
			opN[2]++;
		}
		if (opN[3] > 0) {
			opN[3]--;
			dfs(index + 1, now / arr[index]);
			opN[3]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) //수열의 정보 입력
		cin >> arr[i];

	for (int i = 0; i < 4; i++) { //연산의 정보 입력
		int a;
		cin >> a;
		opN.push_back(a);
	}

	dfs(1, arr[0]);

	return 0;
}

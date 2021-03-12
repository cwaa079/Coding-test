//한정된 동전을 가지고 만들 수 없는 최솟값

#include <bits/stdc++.h>

using namespace std;

int n; //동전 개수
vector <int> arr; //화폐 단위

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end()); //정렬

	int target = 1;
	for (int i = 0; i < n; i++){
		if(target<arr[i]) break;
		target += arr[i];
	}
	cout << target << '\n';

	return 0;
}

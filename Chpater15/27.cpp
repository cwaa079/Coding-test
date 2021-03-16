//정렬된 배열에서 특정 수의 개수 구하기

#include <bits/stdc++.h>
using namespace std;

int n, x;
vector <int> arr;

int code_by_range(vector <int>&v, int leftValue, int rightValue)
{
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	int cnt = code_by_range(arr,x,x);

	if (cnt == 0) cout << -1 << '\n';
	else cout << cnt << '\n';

	return 0;
}

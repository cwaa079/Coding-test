//고정점 찾기

#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> arr;

int binarySearch(vector <int> &v, int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (v[mid] == mid) return mid;
	else if (v[mid] > mid) return binarySearch(arr, start, mid-1);
	else return binarySearch(arr, mid + 1, end);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	int result = binarySearch(arr, 0, n - 1);

	cout << result << '\n';

	return 0;
}

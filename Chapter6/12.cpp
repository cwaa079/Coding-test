//두 배열의 원소 교체

#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> a, b;

bool compare(int a, int b) { return a > b; }

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);
	
	for (int i = 0; i < k; i++) {
		if (a[i] < b[i]) swap(a[i], b[i]);
		else break;
	}

	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += a[i];
	}
	printf("%lld\n", result);

	return 0;
}

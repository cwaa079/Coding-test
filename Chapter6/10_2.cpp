//내림차순 정렬

#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;

bool compare(int a, int b) { return a > b; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), compare); //내림차순 정렬
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);

	return 0;
}

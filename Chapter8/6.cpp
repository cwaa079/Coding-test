//개미전사

#include <bits/stdc++.h>
using namespace std;

int n; //식량창고 총개수
vector <int> k;
int d[100];

int main()
{
	cin >> n;

	//식량창고 입력
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		k.push_back(a);
	}

	d[0] = k[0];
	d[1] = max(k[0], k[1]);
	for (int i = 2; i < n; i++) {
		d[i] = max(d[i - 1], d[i - 2] + k[i]);
	}
	cout << d[n - 1] << '\n';

	return 0;
}
